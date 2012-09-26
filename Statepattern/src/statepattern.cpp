//============================================================================
// Name        : statepattern.cpp
// Author      : hl
// Version     :
// Copyright   : Copyright (c) 2012 Tiros
// Description : State Pattern in C++, Ansi-style
//============================================================================

#include "statepattern.h"
#include <iostream>
using namespace std;

void Lift::setState(int state)
{
	State = state;
}

void Lift::open()
{
	switch(State)
	{
	case OPENING_STATE:
		break;
	case CLOSING_STATE:		/// < 如果关闭，则可以打开；同时修改状态为打开状态.
		this->openWithoutLogic();
		this->setState(OPENING_STATE);
		break;
	case RUNNING_STATE:
		Waring(WARNING_2);
		break;
	case STOPPING_STATE:		/// < 如果停止的，则可以打开；同时修改状态为打开状态.
		this->openWithoutLogic();
		this->setState(OPENING_STATE);
		break;
	default:
		break;
	}
}

void Lift::close()
{
	switch (State)
	{
	case OPENING_STATE:		/// < 如果打开的，则可以关闭；同时修改状态为关闭状态.
		this->closeWithoutLogic();
		this->setState(CLOSING_STATE);
		break;
	case CLOSING_STATE:
		break;
	case RUNNING_STATE:
		break;
	case STOPPING_STATE:
		break;
	default:
		break;
	}
}

void Lift::run()
{
	switch (State)
	{
	case OPENING_STATE:
		Waring(WARNING_1);
		break;
	case CLOSING_STATE:		/// < 如果关闭，则可以运行；同时修改状态为运行状态.
		this->runWithoutLogic();
		this->setState(RUNNING_STATE);
		break;
	case RUNNING_STATE:
		break;
	case STOPPING_STATE:	/// < 如果停止的，则可以运行；同时修改状态为运行状态.
		this->runWithoutLogic();
		this->setState(RUNNING_STATE);
		break;
	default:
		break;
	}
}

void Lift::stop()
{
	switch (State)
	{
	case OPENING_STATE:
		break;
	case CLOSING_STATE:		/// <  如果关闭，则可以停止；同时修改状态为停止状态.
		this->stopWithoutLogic();
		this->setState(STOPPING_STATE);
		break;
	case RUNNING_STATE:		/// <  如果运行，则可以停止；同时修改状态为停止状态.
		this->stopWithoutLogic();
		this->setState(STOPPING_STATE);
		break;
	case STOPPING_STATE:
		break;
	default:
		break;
	}
}

void Lift::openWithoutLogic()
{
	cout << "打开门" << endl;
}

void Lift::closeWithoutLogic()
{
	cout << "关门" << endl;
}

void Lift::runWithoutLogic()
{
	cout << "运行" << endl;
}

void Lift::stopWithoutLogic()
{
	cout << "停止" << endl;
}

void Lift::Waring(int errno)
{
	switch(errno)
	{
	case WARNING_1:
		cout << "打开状态下不能运行" << endl;
		break;
	case WARNING_2:
		cout << "运行状态下不能开门" << endl;
		break;
	default:
		break;
	}
}


/// < --------------------------------------

OpenState * Context::openningState = new OpenState();
CloseState * Context::closeingState = new CloseState();

/**
 * @brief 开门状态 - 可以关闭
 */
void OpenState::open()
{
	cout << "电梯门开启..." << endl;
}

void OpenState::close()
{
	context->setLiftState(context->closeingState);
	context->getLiftState()->close();
}

void OpenState::run()
{

}

void OpenState::stop()
{

}

/**
 * @brief 关闭状态 - 可以打开
 */
void CloseState::open()
{
	context->setLiftState(context->openningState);	/// < 设置当前电梯状态为openning状态
	context->getLiftState()->open();				/// < OpenState's liftState打开
}

void CloseState::close()
{
	cout << "电梯门关闭..." << endl;
}

void CloseState::run()	/// < 设置为运行状态；
{

}

void CloseState::stop()	/// < 设置为运行状态；
{

}





int main()
{
	ILift * lif = new Lift();
	lif->setState(ILift::CLOSING_STATE);	/// < 初始为关闭状态

	lif->open();
	lif->run(); 	/// < Warning1
	lif->close();
	lif->run();
	lif->open();	/// < Warning2
	lif->stop();
	/*
	打开门
	打开状态下不能运行
	关门
	运行
	运行状态下不能开门
	停止
	*/

	cout << "---------真正的状态模式-------------------\n";
	Context cont;
	cont.setLiftState(new CloseState());

	cont.close();
	cont.open();
	cont.close();

	return 0;
}
