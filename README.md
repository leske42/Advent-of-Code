# Advent-of-Code

Here are my solutions to Advent of Code, currently for the years 2023 and 2024.

I had to make my old repository private, as [Ildi](https://github.com/cseriildi) has warned me that publishing the input files is against the will of the author of these challenges. Since there is not much sense in just removing them if they are still present in the commit history, I have a brand new repo for all years now. The central makefile in 2023 folder will be still expecting these (usually named `input.txt` and placed either central or in the respective folder), so please provide your own if you want to run test cases.

My solutions for 2023 are in C, and for 2024 in C++.

I was originally ashamed of my 2023 solutions, as I did not get very far and my code was a complete mess. But looking back on it from 2024, I am more proud of it than any result I achieved a year later. I was basically only coding since a total of 3 months back then, and C was the only language I knew. Thanks to 42, I knew nothing about the libc and could only rely on functions I wrote for myself from scratch. Every challenge began like a parsing hell, took 3-4 hours of my day, and despite that, I still kept fighting. Therefore, even though the code itself is definitely not of much value and does not mirror my current understanding or use of the C language, I decided to publish it anyway.

It is also nice to see how differently I code after just a year of additional practice, and I can very much appreciate the power and all the features C++ has to offer. Honestly, I feel spoiled.

I will collect some of the knowledge I picked up in doing the challenges in '24, but it might take me a while to cover every topic.

**Lambda functions and comparators (from day 2)**

This something only from C++11, so sadly we do not cover this at 42. **Lambdas** are tiny, temporary unnamed functions that follow the syntax of `[ capture_list ] ( parameters ) { body }`. Return type is also optionally specified (following a syntax similar to Rust's). <br> `[ capture_list ]` can make variables from outside available in the body scope.

**Comparators** are also tiny functions that define the way two elements are compared in a function or a data structure. This is useful for example if you want to implement a custom way of sorting. Some functions like `std::sort` take an optional function parameter, where it is possible to pass your custom comparator, *for example, in the form of a lamba expression*.

There is also the weird concept of **function objects** coming up in this topic. Function objects are important because some data structures (say an `std::map`) need a comparator for their entire lifetime, therefore we need to come up with a way for them to *store it*. A function, however, can not be stored as it takes up no space in memory. Normally function pointer would solve this issue, but in C++ there is a trickier (and ultimately more convenient) way to do it. If we create a struct or a class that has an overload for operator `()` (the function call operator), we will be able to "call" an object of that class like it was a regular function.

The following code is legimate syntax following this practice and will return `1` on execution:
```
struct Equals
{
    bool operator()(int a, int b) const
    {
        return (a == b);
    }
};

int main()
{
    Equals hehe;
    return (hehe(3, 3));
}
```

And fun fact is that when you define a lambda function, compiler will actually make a function object for you, like the one above.
