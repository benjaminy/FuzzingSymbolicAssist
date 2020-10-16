# Top Matter

CC = clang
CFLAGS = -O1 -g -fno-omit-frame-pointer -fno-optimize-sibling-calls

clean:
	rm -rf Scratch/*
	rm -rf Build/*

Build/math-1 : math-1.c
	$(CC) $(CFLAGS) -fsanitize=fuzzer -o $@ $<

Build/math-2 : math-2.c
	$(CC) $(CFLAGS) -fsanitize=fuzzer -o $@ $<

run-experiment : Build/math-1 Build/math-2
	mkdir -p Scratch
	cd Scratch && ../experiment.py
