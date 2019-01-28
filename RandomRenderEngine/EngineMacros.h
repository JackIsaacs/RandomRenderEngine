#pragma once

#define DELETECHECKED(object) { if (object != nullptr) { delete object; } }
