# FuzzingSymbolicAssist
An idea for improving fuzz testing

## The Observation - Fuzzing and Concolic Testing

Fuzzing in the form of tools like AFL and libfuzzer is rapidly gaining traction in mainstream software engineering practice.
At the heart of these tools is a feedback loop that uses control flow coverage information to guide a random search through some input space.
This works remarkably well for finding certain kinds of bugs in software.
However, certain kinds of programming logic do not play nicely with these fuzzers; that is, they have a hard time "learning" what inputs will drive a program down certain paths.

Concolic testing tools like KLEE and SAGE make a substantially different tradeoff.
They use logical formulas and SMT solvers to more directly connect input values to particular paths through a program.
However, these tools have scaling issues, struggle with uninstrumented code, and have so far had only a modest impact on mainstream software engineering practice.

## The Hypothesis - Making Fuzzing a Little Better

Fuzzers like AFL and libfuzzer use control flow to guide their random search process.
The example in this repo suggests that it might be possible to improve that search process by replaceing "hard" control flow choices by a collection of "easier" choices.
In particular, this example asks the fuzzer for 3 64-bit numbers such that the third is the product of the first 2.
(There are a few additional constraints to rule out trivial solutions like 0, 0, 0.)
When the equality is a plain `==`, this test runs for anywhere from a couple of seconds to several minutes on my computer.
However, when the equality is broken up into 64 individual bit equality tests it consistently completes in less than a second.
(I make no claim that this particular way of breaking up the equality is especially clever.)

So this tiny example makes me wonder if there might be a way of hybridizing fuzzing and symbolic execution that hasn't been explored yet.
That is:
- Run a stock fuzzer for a while until it discovers some hard control flow tests.
- Use a symbolic analysis tool to _locally_ figure out a way of decomposing the hard control flow into multiple tests that might represent an easier "ramp" for the fuzzer.
