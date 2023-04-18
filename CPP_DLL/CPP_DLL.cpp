// CPP_DLL.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "CPP_DLL.h"

#include <cstdint>

CPPDLL_API void GaussianFilter(BYTE* pixelmap, int bi_size_image, int subpx_width, int start_pos, int end_pos, int sharpening_amount)
{
    const float f_sharpening_amount = sharpening_amount / static_cast<float>(100);

    const uint_fast8_t kernel[] = {
        1, 2, 1,
        2, 4, 2,
        1, 2, 1
    };

    if (start_pos < subpx_width)
    {
        start_pos = subpx_width;
    }

    if (end_pos > bi_size_image - subpx_width)
    {
        end_pos = bi_size_image - subpx_width;
    }

    for (int i = start_pos; i < end_pos; i += 3)
    {
        int_fast16_t B =
            (kernel[0] * pixelmap[i - subpx_width - 3]
                + kernel[1] * pixelmap[i - subpx_width]
                + kernel[2] * pixelmap[i - subpx_width + 3]
                + kernel[3] * pixelmap[i - 3]
                + kernel[4] * pixelmap[i]
                + kernel[5] * pixelmap[i + 3]
                + kernel[6] * pixelmap[i + subpx_width - 3]
                + kernel[7] * pixelmap[i + subpx_width]
                + kernel[8] * pixelmap[i + subpx_width + 3]
                ) / 16;

        int_fast16_t G =
            (kernel[0] * pixelmap[i + 1 - subpx_width - 3]
                + kernel[1] * pixelmap[i + 1 - subpx_width]
                + kernel[2] * pixelmap[i + 1 - subpx_width + 3]
                + kernel[3] * pixelmap[i + 1 - 3]
                + kernel[4] * pixelmap[i + 1]
                + kernel[5] * pixelmap[i + 1 + 3]
                + kernel[6] * pixelmap[i + 1 + subpx_width - 3]
                + kernel[7] * pixelmap[i + 1 + subpx_width]
                + kernel[8] * pixelmap[i + 1 + subpx_width + 3]
                ) / 16;

        int_fast16_t R =
            (kernel[0] * pixelmap[i + 2 - subpx_width - 3]
                + kernel[1] * pixelmap[i + 2 - subpx_width]
                + kernel[2] * pixelmap[i + 2 - subpx_width + 3]
                + kernel[3] * pixelmap[i + 2 - 3]
                + kernel[4] * pixelmap[i + 2]
                + kernel[5] * pixelmap[i + 2 + 3]
                + kernel[6] * pixelmap[i + 2 + subpx_width - 3]
                + kernel[7] * pixelmap[i + 2 + subpx_width]
                + kernel[8] * pixelmap[i + 2 + subpx_width + 3]
                ) / 16;

        int_fast16_t a = pixelmap[i];
        int_fast16_t b = pixelmap[i + 1];
        int_fast16_t c = pixelmap[i + 2];

        int_fast16_t d = a + (a - B) * f_sharpening_amount;
        int_fast16_t e = b + (b - G) * f_sharpening_amount;
        int_fast16_t f = c + (c - R) * f_sharpening_amount;

        if (0 < d and d < 255)
            pixelmap[i] = d;

        if (0 < e and e < 255)
            pixelmap[i + 1] = e;

        if (0 < f and f < 255)
            pixelmap[i + 2] = f;
    }
}