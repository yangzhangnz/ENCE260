#include "system.h"  // This has the F_CPU definition
#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
    system_init ();

    /* Initialise port to drive LED 1.  */
    
    // Configure pin #2 of port C as an output.
    // DDR（数据方向寄存器）决定端口上的每个引脚是输入还是输出。在这里，我们使用按位 OR ( |=) 运算将端口 C 的引脚 #2 设置为输出，而不影响其他引脚。
    //DDRC |= (1 << 2);

    // 端口 D (DDRD) 的数据方向寄存器必须将位 #7 设置为 0，才能将其配置为输入。
    DDRD &= ~(1 << 7);

    while (1)
    {   /* Turn LED 1 on.  */
        // Set the state of pin #2 of port C to HIGH, which turns the LED on.
        //这会将端口 C 的引脚 #2 设置为高电平状态。对于 LED，这通常意味着它将打开，但实际行为可能取决于 LED 的接线方式（共阳极与共阴极）。
        //PORTC |= (1 << 2);

        // Optional: Introduce delay for blinking effect
        // 引入 500 毫秒的延迟。它是可选的，如果您愿意，这里使用它只是为了提供 LED 闪烁效果。如果您只想让 LED 保持常亮而不闪烁，则可以删除此行。
        //_delay_ms(500); 

        if (PIND & (1 << 7)) {
            PORTC |= (1 << 2); // Turn LED on
        } else {
            PORTC &= ~(1 << 2); // Turn LED off
        }
    }
}
