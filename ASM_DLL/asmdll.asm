.data

kernel:
word 1
word 1
word 1
word 2
word 2
word 2
word 1
word 1
word 1
word 2
word 2
word 2
word 4
word 4
word 4
word 2
word 2
word 2
word 1
word 1
word 1
word 2
word 2
word 2
word 1
word 1
word 1

word 1
word 1
word 1
word 2
word 2
word 2
word 1
word 1
word 1
word 2
word 2
word 2
word 4
word 4
word 4
word 2
word 2
word 2
word 1
word 1

.code
GaussianFilter proc
push rbp
mov rbp, rsp
;image->pixel_array - RCX -> RBX
;image->info_header_biSizeImage - RDX -> R15
;subpx_width - R8
;start_pos - R9
;end_pos - [rsp+8*5] - R13
;sharpening_amount - [rsp+8*6] - r14

push r15
push r14
push r13
push r12
push rbx

mov r13, qword ptr[rsp+8*11]
mov r14, qword ptr[rsp+8*12]
mov r15, rdx ;move bi_size_iamge to R15
mov rbx, rcx ;move bitmap address to RBX

;load gauss kernel to zmm- registers
vmovdqu64 zmm0, zmmword ptr[kernel]
vmovdqu64 zmm1, zmmword ptr[kernel + 6]
vmovdqu64 zmm2, zmmword ptr[kernel + 12]
vmovdqu64 zmm3, zmmword ptr[kernel + 18]
vmovdqu64 zmm4, zmmword ptr[kernel + 24]
vmovdqu64 zmm5, zmmword ptr[kernel + 30]

;;;vmovdqu64 zmm31, qword ptr[mask255]
;;;vmovdqu64 zmm30, qword ptr[mask0]

;load sharpening_amount to zmm16 register and fill
vmovd xmm11, r14
vpermq zmm11, zmm11, zmm11

vmovd xmm12, r14
vpaddq zmm16, zmm11, zmm12

;fill zmm17 with 64h's

mov rax, 64h
vmovd xmm11, rax
vpermq zmm11, zmm11, zmm11

vmovd xmm12, rax
vpaddq zmm17, zmm11, zmm12
vcvtqq2pd zmm17, zmm17

;condition if (start_pos < subpx_width)
;	{
;		start_pos = subpx_width;
;	}
cmp r9, r8 ;compare start_pos to subpx_width
jg endof_condition1
mov r9, r8
endof_condition1:

;condition if (end_pos > bi_size_image - subpx_width)
;	{
;		end_pos = bi_size_image - 2*subpx_width;
;	}
mov rax, r15 ;move bi_size_image to rax
sub rax, r8 ;subtract subpx_width from rax
cmp rax, r13 ;compare end_pos to bi_size_image - subpx_width
jg endof_condition2
mov r13, rax ;move bi_size_image - subpx_width to r13 (new end_pos)
endof_condition2:

;checking the condition and entering main loop
mov rcx, r9 ;move start_pos to rcx (counter)
cmp r9, r13 ;compare start_pos to end_pos
jl gaussian_loop
jmp endof_algorithm

;algorithm loop:
gaussian_loop:
mov rax, rbx ;move bitmap address to rax
add rax, rcx ;add counter offset to rax

sub rax, r8

;read values from bitmap memory to zmm- registers
vpmovzxbw zmm6, ymmword ptr[rax] 
vpmovzxbw zmm7, ymmword ptr[rax + 3]
vpmovzxbw zmm8, ymmword ptr[rax + 6]
add rax, r8 ;move addres with the offset of subpx_width
vpmovzxbw zmm9, ymmword ptr[rax]
vpmovzxbw zmm10, ymmword ptr[rax + 3]
vpmovzxbw zmm19, ymmword ptr[rax + 3]
vpmovzxbw zmm11, ymmword ptr[rax + 6]
add rax, r8 ;move addres with the offset of subpx_width
vpmovzxbw zmm12, ymmword ptr[rax]
vpmovzxbw zmm13, ymmword ptr[rax + 3]
vpmovzxbw zmm14, ymmword ptr[rax + 6]
sub rax, r8

vpmullw zmm6, zmm0, zmm6 ;multiplying pixel values by kernel
vpmullw zmm7, zmm1, zmm7
vpmullw zmm8, zmm2, zmm8

vpmullw zmm9, zmm3, zmm9
vpmullw zmm10, zmm4, zmm10
vpmullw zmm11, zmm5, zmm11

vpmullw zmm12, zmm0, zmm12
vpmullw zmm13, zmm1, zmm13
vpmullw zmm14, zmm2, zmm14

vpaddw zmm15, zmm6, zmm15 ;addition of multiplied values
vpaddw zmm15, zmm7, zmm15
vpaddw zmm15, zmm8, zmm15
vpaddw zmm15, zmm9, zmm15
vpaddw zmm15, zmm10, zmm15
vpaddw zmm15, zmm11, zmm15
vpaddw zmm15, zmm12, zmm15
vpaddw zmm15, zmm13, zmm15
vpaddw zmm15, zmm14, zmm15

vpsrlw zmm15, zmm15, 4 ;bitshift left by 4 bits (multiply by 16)

vpmovsxwq zmm18, xmm15 ;unpack from xmm15 to zmm18
vpmovsxwq zmm19, xmm19 ;unpack original image from to qword
vpsubq zmm20, zmm19, zmm18 ;subtract original image from calculated blur
vpmullq zmm20, zmm20, zmm16 ;multiply subtracted blur times sharpening amout
vcvtqq2pd zmm21, zmm20 ;convert above to double
vdivpd zmm22, zmm21, zmm17 ;divide above / 64h (doubles)
vcvtpd2qq zmm23, zmm22 ;truncate division to qwords
vpaddq zmm23, zmm23, zmm19 ;add to above original image once again

vpmovqw xmm6, zmm23 ;move to xmm6 register for export

pextrw rdx, xmm6, 0 ;export B value
cmp rdx, 0ffh
jge skipB
cmp rdx, 0
jle skipB
mov byte ptr[rax + 3], dl
skipB:

pextrw rdx, xmm6, 1 ;export G value
cmp rdx, 0ffh
jge skipG
cmp rdx, 0
jle skipG
mov byte ptr[rax + 4], dl
skipG:

pextrw rdx, xmm6, 2 ;export R value
cmp rdx, 0ffh
jge skipR
cmp rdx, 0
jle skipR
mov byte ptr[rax + 5], dl
skipR:

add rcx, 3
cmp rcx, r13
jl gaussian_loop

endof_algorithm:
pop rbx
pop r12
pop r13
pop r14
pop r15
mov rsp, rbp
pop rbp
ret
GaussianFilter endp
end