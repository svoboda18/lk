/*
 * Copyright (c) 2008 Travis Geiselbrecht
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef __MTK_CFB_H
#define __MTK_CFB_H

extern void fbcon_display_image(const unsigned int data[],
		unsigned int xpos, unsigned int ypos, unsigned int width, unsigned int height);
extern void fbcon_set_color(unsigned int bg, unsigned int fg);
extern void fbcon_clear(void);
extern void fbcon_set_position(unsigned int x, unsigned int y);
extern void fbcon_get_position(unsigned int *x, unsigned int *y);
extern void fbcon_disp_string(int font_scale,const char *s);
extern void fbcon_clear_image(const unsigned int data,
		unsigned int xpos, unsigned int ypos, unsigned int width, unsigned int height);

#endif

