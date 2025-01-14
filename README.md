# Cpp-Shorts
Short C++ Programs that reflect small concepts learned

- [Cpp-Shorts](#cpp-shorts)
- [Data Type (my brain dump)](#data-type-my-brain-dump)

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
