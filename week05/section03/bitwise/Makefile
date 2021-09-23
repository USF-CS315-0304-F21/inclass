PROG = bitwise
OBJS = main.o get_bit_s.o

%.o: %.c
	gcc -c -g -o $@ $<

%.o: %.s
	as -g -o $@ $<

$(PROG): $(OBJS)
	gcc -g -o $(PROG) $^

clean:
	rm -rf $(PROG) $(OBJS)
