# -------- Project --------
PROJECT := raylib_app
INCDIR  := include
LIBDIR  := lib
BUILDD  := build
BINDIR  := bin

# -------- Toolchain --------
CXX := g++

# -------- OS detection (no uname on Windows) --------
ifeq ($(OS),Windows_NT)
  PLATFORM := WINDOWS
  EXEEXT   := .exe
  MKDIRP   := powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path"
  RM_R     := powershell -NoProfile -Command "Remove-Item -Recurse -Force"
  SYS_LIBS := -lopengl32 -lgdi32 -lwinmm
else
  UNAME_S  := $(shell uname -s)
  PLATFORM := UNIX
  EXEEXT   :=
  MKDIRP   := mkdir -p
  RM_R     := rm -rf
  ifeq ($(UNAME_S),Linux)
    SYS_LIBS := -lGL -lm -lpthread -ldl -lrt -lX11
  endif
  ifeq ($(UNAME_S),Darwin)
    SYS_LIBS := -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo \
                -framework CoreAudio -framework AudioToolbox
  endif
endif

# -------- Source discovery (pure GNU make; no external 'find') --------
# Recursive wildcard
rwildcard = $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) \
             $(filter $(subst *,%,$2),$d))

SRCS := main.cpp $(call rwildcard,classes/,*.cpp)
OBJS := $(SRCS:%.cpp=$(BUILDD)/%.o)
DEPS := $(OBJS:.o=.d)

# -------- Flags --------
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -I$(INCDIR) -MMD -MP
LDFLAGS  := -L$(LIBDIR) -lraylib $(SYS_LIBS)

# -------- Targets --------
.PHONY: all clean run

all: $(BINDIR)/$(PROJECT)$(EXEEXT)

$(BINDIR)/$(PROJECT)$(EXEEXT): $(OBJS) | $(BINDIR)
	$(CXX) $^ -o $@ $(LDFLAGS)

# compile rule; auto-create subfolders for each object
$(BUILDD)/%.o: %.cpp
	@$(MKDIRP) "$(dir $@)" >NUL 2>&1
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BINDIR):
	@$(MKDIRP) "$(BINDIR)" >NUL 2>&1

clean:
	-$(RM_R) "$(BUILDD)" "$(BINDIR)"

run: all
	"./$(BINDIR)/$(PROJECT)$(EXEEXT)"

-include $(DEPS)
