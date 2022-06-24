//
// Created by Collin Diekvoss on 3/4/20.
//

#include "shell.hpp"
#include <string>
#include <vector>

PipeType eval_cmd(const std::string &cmd) {
  PipeType result = NOTHING;
  std::string token;
  if (token == "|")
    result = PIPE;
  else if (token == "<")
    result = REDIRECT_IN;
  else if (token == ">")
    result = REDIRECT_OUT;
  else if (token == ">>")
    result = REDIRECT_APPEND;

  return result;
}