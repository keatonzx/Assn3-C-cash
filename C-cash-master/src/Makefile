all: tunit punit bunit cunit

tunit: trnslist.h trnslist.c tlist-test-unit.c
	gcc trnslist.c tlist-test-unit.c -o tunit

punit: puzzle.h puzzle.c puzzle-test-unit.c
	gcc puzzle.c puzzle-test-unit.c sha1/sha1.c -o punit

bunit: puzzle.h puzzle.c trnslist.h trnslist.c block.h block.c block-test-unit.c
	gcc puzzle.c trnslist.c block.c block-test-unit.c sha1/sha1.c -o bunit
	
cunit: puzzle.h puzzle.c trnslist.h trnslist.c block.h block.c blockchain.c blockchain.h bctest.c
	gcc puzzle.c trnslist.c block.c blockchain.c  bctest.c sha1/sha1.c -o cunit

clean:
	@rm -f *.o tunit punit bunit cunit