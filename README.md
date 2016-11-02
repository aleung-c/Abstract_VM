# Abstract_VM
A c++ virtual machine executing simple assembly code.

This project is a C++ virtual machine. The goal was to start getting acquainted with virtual programmation.
Indeed, what is a virtual machine, if not a machine without physical component?

In this project, we had to give input to the machine (mainly small assembly codes) and execute them through our machine,
in order to give the asked output.

The interesting part lies in the architecture of the machine. Although we are free to define the machine we want,
I wanted to have virtual parts that have meaning, similar to a real machine. This is why I separated my classes
into virtual components, namely the InputController and the VirtualProcessor, all controlled by the main VMController.

This kind of parent children programming style gives a somewhat separated code, that makes each class look like a physical
component of the machine.
