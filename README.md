1. clear instructions within the README of how to run the code (including any setup needed for the graders)

## How to run

To run the code either the person can compile the main and keyStore.h file themselves or they can just download the main.exe. Either one should return the same results.

To compile take a look at https://stackoverflow.com/questions/11365850/run-c-in-command-prompt-windows to get a better understanding

2. write-up within the README of how this assignment should be modified in order to become an “official” assignment in the
   future (consider clarifications to the instructions, different methods that should be written, more effective ways to grade, or any other aspect!)

## Improvements to the assignment

I think some better clarification for what the interface should look like would help. Should this read the instructions in from a textfile? An actual visual UI? from the terminal? I think the terminal is sufficient but some guidance around this would have been helpful. In addition different languages handle things very differently. In one language a runtime exception may be a completely different thing than in another language. In addition a Null in one language is also used differently in another language.

In addition some level of constraints would be nice. Like to what is something permissible. Since there actual enterprise software solutions for key-value stores there should be some concrete limits as to what should be completed / expected.

Also this assignment is already pretty big but if some research would need to be done into different types of in memory key-value stores that would be nice. Then you have a wider "variety" of key-value stores to choose from.

## Improvements to the database itself
1. Add tcp interface
2. Add a blob based value
3. Have an LRU memory management
4. Have Snapshots
