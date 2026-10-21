/* 案例：频率合成驱动移植中的整型问题
 * 场景：Fvco=VCO频率, xtal=晶振频率, 参考 ref = xtal*7
 * 注：截图为博客片段，原始变量声明不可见；按典型嵌入式约定假设：
 *     Fvco/xtal 为 32 位无符号，demo 行 chan_frac 为有符号整型。
 */

/* ---- demo 原版（博客称"正确"的有符号路径）---- */
chan_frac = (((Fvco % (xtal*7)) - (xtal*7)) << 12) / ((xtal*7) >> 4);

/* ---- 移植版（博客指认 UINT32 中间变量为"元凶"）---- */
UINT32 chan_frac_v;    /* 博客注释：+ 元凶 */
chan_frac_v = (((Fvco % (xtal*7UL)) - (xtal*7UL)) << 12) / ((xtal*7UL) >> 4);
