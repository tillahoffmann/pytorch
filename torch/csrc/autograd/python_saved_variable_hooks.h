#pragma once

#include <pybind11/pybind11.h>
#include <torch/csrc/autograd/python_variable.h>
#include <torch/csrc/autograd/saved_variable_hooks.h>
#include <torch/csrc/python_headers.h>
#include <ATen/ATen.h>

namespace py = pybind11;

namespace torch { namespace autograd {

struct TORCH_API PySavedVariableHooks : public SavedVariableHooks {
    PySavedVariableHooks(py::function &pack_hook, py::function &unpack_hook) : pack_hook_(pack_hook), unpack_hook_(unpack_hook){}

    void call_pack_hook(at::Tensor &tensor) override {
      TORCH_CHECK_NOT_IMPLEMENTED(false, "Hooks are not implemented yet");
    }

    at::Tensor call_unpack_hook() override {
      TORCH_CHECK_NOT_IMPLEMENTED(false, "Hooks are not implemented yet");
    }

    ~PySavedVariableHooks() override = default;

  private:
    py::function pack_hook_;
    py::function unpack_hook_;
};

}}
