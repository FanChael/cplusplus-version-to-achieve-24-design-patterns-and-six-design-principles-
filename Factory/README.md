说明：
    练习到目前为止，像策略模式，代理模式等实现基本都是虚函数的功劳！让派生类去实现基类的行为，再让基类表现出派生类的行为.当然，其中需要用到static这个可以让函数脱离对象的存在而存在，这样我们直接调用函数就可以了，而不需要去创建一个对象！这在单模式中必须的！

    顺便说下重载，覆盖，隐藏。（终于算是理解了，只是理解）
    1.重载 同类中，同名不同参
    2.覆盖 基类和派生类中，同名同参（基类+virtual）
    3.隐藏 分两种情况：
            1.基类和派生类中，同名不同参，基类有/无virtual
            2.基类和派生类中，同名同参，基类无virtal
