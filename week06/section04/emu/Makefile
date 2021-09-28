PROG = emu

OBJS = emu.o add2.o 

%.o: %.c
	gcc -c -g -o $@ $<

%.o: %.s
	as -g -o $@ $<

$(PROG): $(OBJS)
	gcc -g -o $@ $(OBJS)

clean:
	rm -rf $(PROG) $(OBJS)
