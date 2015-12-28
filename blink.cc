#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 250

int main(void)
{
        //DDRB |= _BV(DDB5);
        DDRB |= _BV(DDB4);
        DDRB |= _BV(DDB3);
        DDRB |= _BV(DDB2);

        while (1) {
                //PORTB |= _BV(PORTB5);
                PORTB |= _BV(PORTB2);
                PORTB &= ~_BV(PORTB4);
                PORTB &= ~_BV(PORTB3);
                _delay_ms(BLINK_DELAY_MS);

                PORTB |= _BV(PORTB3);
                PORTB |= _BV(PORTB4);
                //PORTB &= ~_BV(PORTB5);
                PORTB &= ~_BV(PORTB2);
                _delay_ms(BLINK_DELAY_MS);
        }
}
