//> using scala "2.13.12"
//> using dep "org.chipsalliance::chisel:6.3.0"
//> using plugin "org.chipsalliance:::chisel-plugin:6.3.0"
//> using options "-unchecked", "-deprecation", "-language:reflectiveCalls", "-feature", "-Xcheckinit", "-Xfatal-warnings", "-Ywarn-dead-code", "-Ywarn-unused", "-Ymacro-annotations"

import chisel3._
// _root_ disambiguates from package chisel3.util.circt if user imports chisel3.util._
import _root_.circt.stage.ChiselStage
import java.io._

class RegisterModule extends Module {
  val io = IO(new Bundle {
    val in  = Input(UInt(12.W))
    val out = Output(UInt(12.W))
  })
  
  val register = Reg(UInt(12.W))
  register := io.in + 1.U
  io.out := register
}

object Main extends App {
  val outputFile = new File("example.sv") // 定义输出文件
  val writer = new PrintWriter(outputFile) // 创建文件写入器

  // 将 Chisel 代码输出到文件
  writer.write(
    ChiselStage.emitSystemVerilog(
      gen = new RegisterModule,
      firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")
    )
  )

  // 关闭文件写入器
  writer.close()
}