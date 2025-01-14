# Cpp-Shorts
Short C++ Programs that reflect small concepts learned

- [Cpp-Shorts](#cpp-shorts)
- [Data Type (my brain dump)](#data-type-my-brain-dump)
- [Variable Initializiation](#variable-initializiation)
- [Attribute: \[\[maybe\_unused\]\]](#attribute-maybe_unused)

# Data Type (my brain dump)
In C++ we require that each object must have an associated Data type and the reason being that the compiler can actually
allot some memory to that object in Random Access Memory (RAM).

From the above brief it is clear that all objects - primitive types, custom data types all have one thing in common that
each of them have some memory associated with it.

Also using the learnings from Computer Architecture is that all data is stored in some binary inside RAM which means for
all types once we define how much byte it takes at RAM level - there is also the idea of each type being able to 
serialize their data from the byte-level in RAM.

Here are some more key concepts associated with this that: The custom data types have variable sizes which means that a
compiler must be capable enough to understand the underlying Architecture and introduce padding bytes that will allow a
for correct and efficient storage with respect to that Architecture.

This meanns there needs to be a standard for each type that has a way to serialize and de-serialize all of their binary
data effectively and be consistent across different Architecture.


# Variable Initializiation
The idea of initializiation is that it will tell the compiler that we are defining a new variable and also adding a 
value to it that is also defined and can be immediately used.

There are 5 different type of initializiation:

1. Default initializiation - it is something that allows for any garbage value to present
2. Copy initializiation - used primarily for primitive types where we copy using `operator=` from rhs to lhs
3. Direct initializiation - uses a pair of parenthesis where it was primarily used for complex types initializiation
4. Direct List initializiation - uses pair of curly braces that are used to provide direct values
5. Value Initializiation - this also uses pair of curly braces but without any value in between - to zero/default

We primarily use Direct List as it directly provides the value that we are interested in but this is not always case as
with use of constructors and we also use Direct initializiation when using with `static_cast<>`.

Another advantage of Direct List is that it prevents narrow type conversion such as `int w{4.5};` will lead to compiler
error.

An easy way to remember these initializiations is with the idea of: No initializiation, Equal to copy, parenthesis, 
braces with specific value and braces with no value.


# Attribute: [[maybe_unused]]

This attribute is used for variables that are defined but it is possible that they may not be used - leading to warnings
that a variable was not used. Using `[[maybe_unused]]` suppresses that warning allowing for easy compilation.
