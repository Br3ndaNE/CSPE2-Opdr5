#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command {
public:
    virtual void Execute() = 0;
    virtual void Undo() = 0;
};

#endif // COMMAND_HPP
