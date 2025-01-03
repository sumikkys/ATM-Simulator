# ATM 模拟程序

## 项目概述

这是一个基于 Qt 与 SQLite 的 ATM 柜员机模拟程序，提供了基本的 ATM 功能，包括账户登录、查询余额、取款、存款、转账、修改密码、开卡与销户, 用于模拟 ATM 的核心功能。本项目为四川大学软件学院C++课程设计。
## 功能

1. **账户登录**：
   - 用户通过输入卡号和密码登录系统。
   - 初始卡号和密码为 `123456`。
   - 登录失败时会提示用户密码或账号不存在。


  ![loginWidget](images/login.png)

2. **主界面**：
   - 在最初登陆时余额将被隐藏，保护用户隐私。
   - 显示账户的当前余额。初始余额为 `10000` 元。
   - 点击各功能按钮前往各个功能模块。


![mainWidget](images/mainWidget.png)

3. **存款**：
   - 用户可以存款，存款金额不能为负数。
   - 存款完成后会实时更新账户余额。


![depositWidget](images/deposit.png)

4. **取款**：
   - 用户可以取款，每次取款金额必须是 `100` 的倍数。
   - 总取款金额不超过 `5000` 元。
   - 不允许透支。
   - 取款完成后会实时更新账户余额。


![withdrawWidget](images/withdraw.png)



5. **修改密码**：
   - 用户可以修改密码，新密码必须满足以下条件：
     - 长度为 6 位。
     - 不允许出现 6 位完全相同的情况。
     - 新密码必须与确认密码匹配。
     - 旧密码必须正确。


![changePassword](images/changePwd.png)




6. **转账**:
   - 用户可以输入目标卡号和金额转账。
   - 转账后会实时更新用户余额。


![transferWidget](images/transfer.png)

7. **开卡/销户**:
   - 用户可以输入卡号与密码进行开卡/销户操作。
   - 开卡时卡号不允许重复。
   - 销户时指定卡号必须存在。
   - 密码必须与确认密码匹配。


![credesWidget](images/credes.png)

## 类结构

![classDiagram](images/classDiagram.png)


- AtmSystem: ATM 后端系统
- MainWindow: ATM 前端处理模块
- Account: 账户类
- LoginWidget: 登陆模块
- MainWidget: 主界面
- DepositWidget: 存款模块
- WithdrawWidget: 取款模块
- ChangePasswordWidget: 修改密码模块
- TransferWidget: 转账模块
- AccountCreDesWidget: 开卡/销户模块

## 目录结构

![directory](images/directories.png)

## 数据库结构

数据库使用 SQLite 搭建，具体结构为：

Accounts 表:

![Accounts_table](images/table_fields.png)

| 字段            | 数据类型       | 约束             |
|-----------------|----------------|------------------|
| account_id      | INTEGER        | 主键，自动递增   |
| card_number     | TEXT           | 唯一，不为空     |
| hashed_password | TEXT           | 不为空           |
| balance         | INTEGER        | 不为空           |



Transactions 表:

| 字段名            | 数据类型      | 约束             | 描述                       |
|--------------------|---------------|------------------|----------------------------|
| transaction_id     | INTEGER       | 主键，自增       | 交易记录的唯一标识         |
| account_id         | INTEGER       | 外键，不为空     | 关联的账户 ID              |
| target_account_id  | INTEGER       | 外键，可为空     | 目标账户（转账时使用）     |
| transaction_type   | TEXT          | 不为空           | 交易类型（如 deposit, withdraw, transfer） |
| amount             | INTEGER          | 不为空           | 交易金额                   |
| timestamp          | TEXT          | 默认当前时间     | 交易时间                   |
| description        | TEXT          | 可为空           | 交易备注或描述             |

### 说明：
- `transaction_id` 是主键，用于唯一标识每笔交易。
- `account_id` 表示发起交易的账户，外键关联 `accounts` 表中的 `account_id`。
- `target_account_id` 用于转账时记录目标账户，可以为空。
- `transaction_type` 存储交易类型，例如存款（`deposit`）、取款（`withdraw`）、转账（`transfer`）等。
- `amount` 表示交易金额
- `timestamp` 默认存储交易发生的时间。
- `description` 可选，用于记录额外信息，如交易备注。


## 编译和运行

1. **编译**：
   - 确保已安装 Qt6 开发环境。
   - 使用 Qt Creator 打开项目。
   - 选择合适的构建配置（Debug 或 Release）。
   - 进行编译。

2. **运行**：
   - 在 Qt Creator 中运行项目。
   - 启动应用程序并测试各项功能。

## 注意事项

- 程序的初始卡号和密码为 `123456`。
- 账户余额在内部作为以分为单位的整型进行处理。
- 密码修改功能要求密码长度正好为 6 位，且不允许出现 6 位完全相同的情况。

## 许可证

本项目使用 [MIT 许可证](LICENSE) 进行分发。

## 联系

如有任何问题或反馈，请通过 [me@sumi.link](mailto:me@sumi.link) 联系我。