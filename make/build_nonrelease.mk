NONRELEASE_TOP := ../../../../internal/bootloader/lk
NONRELEASE_BUILDDIR := $(BUILDDIR)/nonrelease
$(info NONRELEASE_OBJS=$(NONRELEASE_OBJS))
NON_OBJS := $(notdir $(NONRELEASE_OBJS))
$(info NON_OBJS=$(NON_OBJS))

NON_ROBJS := $(addprefix $(NONRELEASE_BUILDDIR)/,$(NON_OBJS))
$(info NON_ROBJS=$(NON_ROBJS))

$(NONRELEASE_BUILDDIR)/%.o: $(NONRELEASE_TOP)/*/%.c $(SRCDEPS)
	@$(MKDIR)
	@echo compiling $<
	$(NOECHO)$(CC) $(CFLAGS) $(THUMBCFLAGS) --std=c99 $(INCLUDES) -c $< -MP -MD -MT $@ -MF $(@:%o=%d) -o $@

