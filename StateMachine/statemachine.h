#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <QObject>

struct KeyEvent{
    enum event{
        keyReleased = 0,
        keyPressed,
        keyDoubleReleased,
        keyLongReleased,
    };
};

struct StateType
{
    enum Enumeration {
        SelfCheck,
        Mark,
        Runtime,
        Intermediate,
    };
};

class StateMachine;

class State
{
public:
    State(StateMachine *stateMachine) {
        mStateMachine = stateMachine;
    }

    inline StateMachine *getStateMachine(){
        return mStateMachine;
    }

    virtual void enter() = 0;
    virtual void exit() = 0;
    virtual void handleKeyEvent(KeyEvent::event e) = 0;

private:
   StateMachine *mStateMachine;
};

class SelfCheckState : public State
{
public:
    SelfCheckState(StateMachine *stateMachine);
    void enter();
    void exit();
    void handleKeyEvent(KeyEvent::event e);
};

class MarkState : public State
{
public:
    MarkState(StateMachine *stateMachine);
    void enter();
    void exit();
    void handleKeyEvent(KeyEvent::event e);
};

class RuntimeState : public State
{
public:
    RuntimeState(StateMachine *stateMachine);
    void enter();
    void exit();
    void handleKeyEvent(KeyEvent::event e);
};

class IntermediateState : public State
{
public:
    IntermediateState(StateMachine *stateMachine);
    void enter();
    void exit();
    void handleKeyEvent(KeyEvent::event e);
};

class StateMachine : public QObject
{
    Q_OBJECT
public:
    explicit StateMachine(QObject *parent = 0);
    void changeState(quint16 type);
    void goBack();

signals:

public slots:

private:
    State *mCurState;
    State *mOldState;
};

#endif // STATEMACHINE_H
