**機房管理系統簡介**：

機房管理系統是一個基於 C++ 開發的專案，專為學生、老師和管理員設計，旨在提供高效的機房使用和管理服務。該系統允許不同角色的用戶進行登入，並根據角色不同提供相應的功能模組，如申請機房使用、查看預約記錄、管理使用者帳號等。

### 功能描述：
1. **身份登錄**：
   - 學生、老師和管理員根據各自的身份選擇並進行登入。
   - 每位用戶根據學號、教師號或管理帳戶名稱進行身份驗證，輸入密碼後確認登入。

2. **學生功能**：
   - **申請預約**：學生可以根據需求申請機房使用的預約。
   - **查看我的預約**：學生可以查看自己已經提交的預約記錄。
   - **查看所有預約**：學生還能查看其他學生的機房預約情況。
   - **取消預約**：如果學生不再需要機房，可以選擇取消已提交的預約。

3. **老師功能**：
   - **查看所有預約**：老師可以查看所有學生的預約狀態。
   - **審核預約**：老師有權對學生提交的預約進行審核和批准。

4. **管理員功能**：
   - **添加帳號**：管理員可以為系統新增學生或老師帳號。
   - **查看帳號**：管理員可以查看系統中註冊的所有帳號。
   - **查看電腦狀態**：管理員可以查看機房電腦的狀態與可用性。
   - **清空預約**：管理員可以清空所有預約記錄，重置系統。

5. **系統退出**：
   - 所有身份的使用者可以選擇退出系統，登出並返回主頁面。

此系統的開發目標是通過角色管理和多層級功能模組，實現機房使用的有效管理，並通過簡單易用的界面讓不同身份的用戶能夠輕鬆操作。