# FuzzingSymbolicAssist
An idea for improving fuzz testing

## The Observation - Fuzzing and Concolic Testing

Fuzzing in the form of tools like AFL and libfuzzer is rapidly gaining traction in mainstream software engineering practice.
At the heart of these tools is a feedback loop that uses control flow coverage information to guide a random search through some input space.
This works remarkably well for finding certain kinds of bugs in software.
However, certain kinds of programming logic do not play nicely with these fuzzers; that is, they have a hard time "learning" what inputs will drive the control flow past certain tests.

Concolic testing in the form of tools like KLEE and SAGE understand program logic to a great level of precision and can in principle generate input for the gnarliest mess of logic.
However, these tools have scaling issues and have so far had only a modest impact on mainstream software engineering practice.

## The Hypothesis - Making Fuzzing a Little Better

Fuzzers like AFL and libfuzzer use control flow to guide their random search process.
The example in this repo suggests that it might be possible to improve that search process by replaceing "hard" control flow choices by a collection of "easier" choices.
In particular, this example asks the fuzzer for 3 64-bit numbers such that the third is the product of the first 2.
(There are a few additional constraints to rule out trivial solutions like 0, 0, 0.)
