<head>
  <link rel="stylesheet" type="text/css" href="https://cdn.jsdelivr.net/gh/aaaakshat/cm-web-fonts@latest/fonts.css">
  <style>
    body {
      font-family: "Computer Modern Serif", serif;
    }
  </style>
</head>

# Gaussian Image Filtering AVX512

## Main features of the project
- Desktop application for sharpening images
- The graphical user interface allows for selecting an image, choosing the number of threads and the type of library that will be loaded for image processing
- Creating Dynamic Linked Libraries written in C and ASM implementing filtering algorithm
- The assembly DLL uses AVX512 vector instructions
- The program contains an algorithm for measuring execution time of the libraries
- Comparison the execution time of libraries written in the C language and assembly

## Used formulas
### Gaussian distribution
$$
    G(x,y) = \frac{1}{2\pi\sigma^{2}}e^{-\frac{x^2+y^2}{2\sigma^2}}
$$

### Formula for image sharpening
$$
    sharpened\ image = original + (original - blurred) \times sharpening factor
$$

### The kernel mask
$$
\frac{1}{16} \times
\begin{array}{c|c|c}
1 & 2 & 1 \\
\hline
2 & 4 & 2 \\
\hline
1 & 2 & 1 \\
\end{array}
$$

## Results
|Before|After|
|:-:|:-:|
|![Before](https://raw.githubusercontent.com/maciagsz/Gaussian-Image-Filtering-AVX512/master/readme/before.jpg)|![After](https://raw.githubusercontent.com/maciagsz/Gaussian-Image-Filtering-AVX512/master/readme/after.jpg)|


