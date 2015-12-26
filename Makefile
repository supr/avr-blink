TARG=blink

CXX=avr-g++
OBJCOPY=avr-objcopy

.PHONY: all deploy

all: $(TARG).hex

deploy: $(TARG).hex
	avrdude -F -V -c usbtiny -p atmega328p -D -U flash:w:$^

clean:
	rm -fr $(TARG) $(TARG).hex $(TARG).o

$(TARG).hex: $(TARG)
	$(OBJCOPY) -O ihex -R .eeprom $^ $@

$(TARG): $(TARG).o
	$(CXX) -mmcu=atmega328p $^ -o $@

%.o: %.cc
	$(CXX) -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o $@ $^
