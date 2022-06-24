//
// Created by Collin Diekvoss on 3/4/20.
//

#ifndef ASSIGNMENT4_SHELL_HPP
#define ASSIGNMENT4_SHELL_HPP
// represents the different possibilities of redirects

#include <string>

enum PipeType { PIPE, REDIRECT_IN, REDIRECT_OUT, REDIRECT_APPEND, NOTHING };

// Splits command into two parts, the command and a second command or file name
PipeType eval_cmd();

// Pipes the output of the first command to the input of the second
void pipe_cmd();

// read input to a command from stdin to some file
void redirect_in_cmd();

// redirect output from some command to a file (overwrite)
void redirect_out_cmd();

// redirect output from some command to append to a file
void redirect_append_cmd();

// execute a command with any arguments
void exe_cmd();

// writes whatever command was entered into a file, weather it was valid or not
void write_history(const std::string &cmd);

// outputs whatever is in history to the screen
void read_history();

#endif // ASSIGNMENT4_SHELL_HPP
