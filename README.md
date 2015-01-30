TBB Patch
============
A Patched Version for Intel(R) Threading Building Blocks - README

We patched Threading Building Blocks to customize the compiler error messages and to explain the misusage. TBB-patch can provide proper compiler error messages when users misuse TBB-patch with typical compilation errors including type mismatch, unsupported type, const qualifier, noncopyable object and outdated method.

The idea behind customizing compiler error messages is to involve strict compile-time checking with two steps,
	1. make the interfaces only accept correct parameters;
	2. make additional overloads accept incorrect parame-ters for capturing the misuses.

The compile-time checking contains all the requirements on types described on the manual.

###Build
If source is present (./Makefile and src/ directories), type 'gmake' in this directory to build and test.

###TBB details
See index.html for directions and documentation.
See examples/index.html for runnable examples and directions.
See http://threadingbuildingblocks.org for full documentation and software information.
