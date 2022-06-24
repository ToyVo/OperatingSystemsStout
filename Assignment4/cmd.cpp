//
// Created by Collin Diekvoss on 3/4/20.
//

#include "cmd.hpp"
#include <sstream>
#include <sys/wait.h>
#include <unistd.h>

PipeType eval_cmd(const std::string &input_cmd, std::string &cmd1,
                  std::string &cmd2) {
  cmd1 = "";
  cmd2 = "";
  std::istringstream stream(input_cmd);
  std::string token;
  PipeType pipeType = NOTHING;
  while (stream >> token) {
    if (pipeType == NOTHING) {
      pipeType = is_token_pipeable(token);
      cmd1 += token;
      cmd1 += " ";
    } else {
      cmd2 += token;
      cmd2 += " ";
    }
  }
  return pipeType;
}

void exe_cmd(const std::string &cmd) {
  char *command[get_number_of_tokens(cmd) + 1];
  convert_str_to_c_string_array(cmd, command);
  pid_t child_pid;
  child_pid = fork();
  if (child_pid == 0) {
    if (execvp(command[0], command) < 0) {
      perror(command[0]);
      exit(EXIT_FAILURE);
    }
  } else if (child_pid < 0) {
    perror("Fork Failed, no new child was created");
    exit(EXIT_FAILURE);
  } else {
    waitpid(child_pid, nullptr, 0);
  }
}

void pipe_cmd(const std::string &cmd1, const std::string &cmd2) {}

void redirect_in_cmd(const std::string &cmd, const std::string &filename) {}

void redirect_out_cmd(const std::string &cmd, const std::string &filename) {}
