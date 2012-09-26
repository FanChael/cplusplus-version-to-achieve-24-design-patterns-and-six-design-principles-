/*
 * statepattern.h
 *
 *  Created on: Sep 26, 2012
 *      Author: hl
 */

#ifndef _STATEPATTERN_H_
#define _STATEPATTERN_H_

/**
 * @brief 电梯动作接口和状态定义
 */
class ILift
{
public:
	virtual void setState(int state) = 0;
public:
	virtual void open() = 0;
	virtual void close() = 0;
	virtual void run() = 0;
	virtual void stop() = 0;
public:
	const static int OPENING_STATE = 1;	/// < 类似java的 public final static int xx = 1;
	const static int CLOSING_STATE = 2;
	const static int RUNNING_STATE = 3;
	const static int STOPPING_STATE = 4;
public:
	const static int WARNING_1 = 1;		/// < 打开状态下不能运行
	const static int WARNING_2 = 2;		/// < 运行状态下不能开门
};

/**
 * @brief 电梯类 - 利用状态的判断(switch case)来实现逻辑结构！代码多了...
 */
class Lift : public ILift
{
public:
	void setState(int state);
public:
	void open();	/// < 打开电梯
	void close();	/// < 关闭电梯
	void run();		/// < 启动电梯
	void stop();	/// < 停止电梯
private:
	void openWithoutLogic();	/// < 打开电梯
	void closeWithoutLogic();	/// < 关闭电梯
	void runWithoutLogic();		/// < 启动电梯
	void stopWithoutLogic();	/// < 停止电梯
private:
	void Waring(int errno);
private:
	int State;
};


/// < -------------真正的状态模式--------------------------


class Context;
/**
 * @brief 电梯动作接口和状态定义
 */
class LiftState
{
public:
	~LiftState()
	{
		if (context)
			delete context;
	}
public:
	void setContext(Context * _context)
	{
		this->context = _context;
	}
public:
	virtual void open() = 0;
	virtual void close() = 0;
	virtual void run() = 0;
	virtual void stop() = 0;
protected:
	Context * context;
};

/**
 * @brief 开门状态
 */
class OpenState : public LiftState
{
public:
	void open();
	void close();
	void run();
	void stop();
};

/**
 * @brief 关闭状态 - 其他状态类似
 */
class CloseState : public LiftState
{
public:
	void open();
	void close();
	void run();
	void stop();
};

/**
 * @brief 运行环境
 */
class Context
{
public:
	~Context()
	{
		if (liftState)
			delete liftState;
		if (openningState)
			delete openningState;
		if (closeingState)
			delete closeingState;
	}
public:
	LiftState * getLiftState() {
		return liftState;
	}
	void setLiftState(LiftState * liftState) {
		this->liftState = liftState;
		//把当前的环境通知到各个实现类中
		this->liftState->setContext(this);
	}
	void open()
	{
		this->liftState->open();
	}
	void close()
	{
		this->liftState->close();
	}
	void run()
	{
		this->liftState->run();
	}
	void stop()
	{
		this->liftState->stop();
	}
public:
	static OpenState * openningState;
	static CloseState * closeingState;
private:
	LiftState * liftState;
};

#endif /* _STATEPATTERN_H_ */
