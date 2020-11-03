DIRECTORIES = $(wildcard */)

all:
	reset
	echo $(DIRECTORIES)
	$(foreach dirz, $(DIRECTORIES), $(MAKE) -C $(dirz);)

clean:
	echo $(DIRECTORIES)
	$(foreach dirz, $(DIRECTORIES), $(MAKE) -C $(dirz) clean;)