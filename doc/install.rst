
安装
====

.. note::

   虽然可以全部用docker，但是还是稍微记录一下吧

Docker
--------

人生苦短，我用Docker。安装步骤参考官网的 `Docker安装 <https://docs.docker.com/engine/install/ubuntu/>`_ 即可。

.. note::

   可以调用这条命令检验docker是否成功安装

   .. code-block:: bash

      docker run --rm hello-world 

Chisel
--------

本项目采用Chisel作为主要的硬件开发语言，所以需要安装Chisel。安装步骤参考官网的 `安装Scala CLI <https://www.chisel-lang.org/docs/installation>`_ 即可。


.. note::

   可以调用这条命令，如同编译成功，则代表安装成功

   .. code-block:: bash

      scala-cli test/example.scala

Verilator
----------
Verilator是一个开源的C++仿真器，它能够仿真Verilog和SystemC。根据我目前的认知，Chisel可以看成是Verilog的代码生成器，最终落地的还是Verilog，这也是我们需要Verilator的原因。

安装步骤参考官网的 `安装Verilator <https://verilator.org/guide/latest/install.html#Verilator%20Executable%20Docker%20Container>`_ ，或者简单调用这条命令

.. code-block:: bash

   bash script/install_verilator.sh 

