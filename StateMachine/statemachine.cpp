#include "statemachine.h"

StateMachine::StateMachine(QObject *parent) : QObject(parent)
{
    mCurState = NULL;
    mOldState = NULL;
}

void StateMachine::changeState(quint16 type)
{
    static SelfCheckState *selfCheckState = new SelfCheckState(this);
    static MarkState *markState = new MarkState(this);
    static RuntimeState *runtimeState = new RuntimeState(this);
    static IntermediateState *intermediateState = new IntermediateState(this);

    if (NULL != mCurState) {
        mCurState->exit();
        mOldState = mCurState;
    }

    switch (type) {
    case StateType::SelfCheck:
        mCurState = selfCheckState;
        break;
    case StateType::Mark:
        mCurState = markState;
        break;
    case StateType::Runtime:
        mCurState = runtimeState;
        break;
    case StateType::Intermediate:
        mCurState = intermediateState;
        break;
    default:
        Q_ASSERT(false);
        break;
    }

    if (NULL != mCurState) {
        mCurState->enter();
    }
}

void StateMachine::goBack()
{
    if (NULL != mCurState) {
        mCurState->exit();
        if (NULL != mOldState) {
            mCurState = mOldState;
            mCurState->enter();
        }
    }
}

SelfCheckState::SelfCheckState(StateMachine *stateMachine):
    State(stateMachine)
{

}

void SelfCheckState::enter()
{

}

void SelfCheckState::exit()
{

}

void SelfCheckState::handleKeyEvent(KeyEvent::event e)
{

}

MarkState::MarkState(StateMachine *stateMachine):
    State(stateMachine)
{

}

void MarkState::enter()
{

}

void MarkState::exit()
{

}

void MarkState::handleKeyEvent(KeyEvent::event e)
{

}

RuntimeState::RuntimeState(StateMachine *stateMachine):
    State(stateMachine)
{

}

void RuntimeState::enter()
{

}

void RuntimeState::exit()
{

}

void RuntimeState::handleKeyEvent(KeyEvent::event e)
{

}

IntermediateState::IntermediateState(StateMachine *stateMachine):
    State(stateMachine)
{

}

void IntermediateState::enter()
{

}

void IntermediateState::exit()
{

}

void IntermediateState::handleKeyEvent(KeyEvent::event e)
{

}
