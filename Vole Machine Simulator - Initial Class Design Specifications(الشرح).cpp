//ده لينك مستند بيشرح فيه وظائف ال (classes)
https://drive.google.com/file/d/1hoec3QEeyNjwSlSLA2yPz4vYgvuAuCx6/view?usp=drive_link



//ده الكوداللي طلعه جيميناي  لل PlantUMl

/* @startuml
skinparam classAttributeIconSize 0
skinparam backgroundColor #FFFFFF
skinparam classBackgroundColor #F9F9F9
skinparam classBorderColor #333333

class Memory {
  - cells: string[256]
  + getCell(address: int): string
  + setCell(address: int, value: string): void
}

class Registers {
  - reg: string[16]
  + getRegister(index: int): string
  + setRegister(index: int, value: string): void
}

class CPU {
  - pc: int
  - instructionRegister: string
  + fetchAndExecute(memory: Memory, registers: Registers): void
  + executeALU(op: string, v1: string, v2: string): string
}

class VoleMachine {
  - memory: Memory
  - registers: Registers
  - cpu: CPU
  + loadProgram(fileName: string): void
  + run(): void
}

VoleMachine *-- Memory
VoleMachine *-- Registers
VoleMachine *-- CPU

@enduml*/
