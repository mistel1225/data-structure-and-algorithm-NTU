source = hw3
all: $(source)
$(source):
%: %.c
	 gcc $< -o $@
%: %.cpp
	 g++ $< -o demo
clean:
	 rm -rf $(source)
run:
	./demo < stdin
