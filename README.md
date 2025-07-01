 # Smart Savings Tracker (C++)
# متعقب المدخرات الذكي (C++)

---

## Overview / نظرة عامة
**English:**
This project is a simple, console-based Smart Savings Tracker developed using C++. It allows users to efficiently manage their personal savings goals, track deposits, and monitor progress towards their financial objectives. The system utilizes text files (`goals.txt` and `transactions.txt`) for persistent data storage, ensuring that all savings data is saved and loaded across application sessions.

**العربية:**
هذا المشروع هو تطبيق بسيط لوحدة التحكم (Console) لمتعقب المدخرات الذكي، تم تطويره باستخدام لغة C++. يسمح للمستخدمين بإدارة أهداف الادخار الشخصية بكفاءة، وتتبع الودائع، ومراقبة التقدم المحرز نحو أهدافهم المالية. يستخدم النظام ملفات نصية (`goals.txt` و `transactions.txt`) لتخزين البيانات بشكل دائم، مما يضمن حفظ وتحميل جميع بيانات الادخار عبر جلسات التطبيق.

---

## Key Features / الميزات الرئيسية
* **Comprehensive Savings Management / إدارة شاملة للمدخرات:**
    * **Add New Goal / إضافة هدف جديد:** Easily create new savings goals by specifying a name, a target amount, and a target date.
        * **إضافة هدف جديد:** يمكنك بسهولة إنشاء أهداف ادخار جديدة عن طريق تحديد اسم ومبلغ مستهدف وتاريخ مستهدف.
    * **Add Savings Deposit / إضافة وديعة ادخار:** Record financial contributions to any of your active savings goals, which automatically updates the current saved amount.
        * **إضافة وديعة ادخار:** سجل المساهمات المالية لأي من أهداف الادخار النشطة لديك، مما يقوم بتحديث المبلغ المدخر الحالي تلقائياً.
* **Intelligent Goal Tracking & Reporting / تتبع الأهداف وإعداد التقارير بذكاء:**
    * **View Goals Report / عرض تقرير الأهداف:** Get a quick overview of all your savings goals, showing their IDs, names, current saved amounts, target amounts, progress percentages, and days remaining until the target date.
        * **عرض تقرير الأهداف:** احصل على نظرة عامة سريعة على جميع أهداف الادخار الخاصة بك، مع إظهار معرفاتها، أسمائها، المبالغ المدخرة الحالية، المبالغ المستهدفة، نسب التقدم، والأيام المتبقية حتى تاريخ الاستحقاق.
    * **View Detailed Goal Information / عرض تفاصيل الهدف:** Access in-depth details for each goal including its creation date, target date, total target amount, current savings, and progress. It also calculates required daily savings to meet the goal on time and displays a full history of all deposits made to that specific goal.
        * **عرض تفاصيل الهدف:** الوصول إلى تفاصيل متعمقة لكل هدف بما في ذلك تاريخ إنشائه، وتاريخ استهدافه، والمبلغ الإجمالي المستهدف، والمدخرات الحالية، والتقدم المحرز. كما يحسب أيضاً مبلغ الادخار اليومي المطلوب لتحقيق الهدف في الوقت المحدد ويعرض سجلاً كاملاً لجميع الودائع التي تمت لهذا الهدف المحدد.
* **Data Persistence Solution / حل استمرارية البيانات:**
    * All savings goals and transaction records are automatically saved to `goals.txt` and `transactions.txt` plain text files, ensuring data integrity and persistence even after closing the application.
        * يتم حفظ جميع أهداف الادخار وسجلات المعاملات تلقائياً في ملفات نصية عادية (`goals.txt` و `transactions.txt`)، مما يضمن سلامة البيانات واستمراريتها حتى بعد إغلاق التطبيق.
* **User-Friendly Console Interface / واجهة تحكم سهلة الاستخدام:**
    * A simple, menu-driven interface guides users through various operations, providing clear prompts and validations for inputs.
        * توجه واجهة بسيطة قائمة على القوائم المستخدمين عبر العمليات المختلفة، مع توفير مطالبات واضحة وتحققات للمدخلات.
* **Automatic ID Generation / توليد المعرف التلقائي:**
    * Each new goal and savings record is assigned a unique ID automatically to ensure proper tracking and management.
        * يتم تعيين معرف فريد لكل هدف جديد وسجل ادخار تلقائياً لضمان التتبع والإدارة السليمة.

---

## Technologies & Concepts Used / التقنيات والمفاهيم المستخدمة
* **Programming Language / لغة البرمجة:** C++
* **Data Structuring / هيكلة البيانات:** `struct` to define `SavingGoal` and `SavingRecord` objects for organizing data attributes. / `struct` لتعريف كائنات `SavingGoal` و `SavingRecord` لتنظيم سمات البيانات.
* **Dynamic Collections / المجموعات الديناميكية:** `std::vector` for dynamic storage and management of `SavingGoal` and `SavingRecord` objects in memory. / `std::vector` للتخزين الديناميكي وإدارة كائنات `SavingGoal` و `SavingRecord` في الذاكرة.
* **File I/O / إدخال/إخراج الملفات:** `fstream` for reading from and writing to text files (`goals.txt`, `transactions.txt`) to maintain persistent data. / `fstream` للقراءة والكتابة من وإلى الملفات النصية (`goals.txt`, `transactions.txt`) للحفاظ على البيانات الدائمة.
* **String Manipulation & Parsing / معالجة النصوص والتحليل:** `std::getline`, `std::istringstream`, `std::stod`, `std::stoi` and `std::get_time` for robust input handling and parsing date/amount strings. / `std::getline`، `std::istringstream`، `std::stod`، `std::stoi` و `std::get_time` للتعامل القوي مع المدخلات وتحليل سلاسل التاريخ/المبالغ.
* **Date and Time Management / إدارة التاريخ والوقت:** `ctime` library functions (`time_t`, `tm`, `mktime`, `difftime`, `strftime`, `localtime_s`) for current date retrieval and calculating differences between dates (e.g., days remaining). / دوال مكتبة `ctime` (`time_t`, `tm`, `mktime`, `difftime`, `strftime`, `localtime_s`) لاسترجاع التاريخ الحالي وحساب الفروق بين التواريخ (مثل الأيام المتبقية).
* **Core Operations / العمليات الأساسية:** Implementation of CRUD (Create, Read, Update, Delete) concepts for goals and transactions. / تطبيق مفاهيم CRUD (إنشاء، قراءة، تحديث، حذف) للأهداف والمعاملات.
* **Input Validation / التحقق من المدخلات:** Robust input validation using `cin.fail()` and `numeric_limits` to ensure users enter valid numeric and date formats. / التحقق القوي من المدخلات باستخدام `cin.fail()` و `numeric_limits` لضمان إدخال المستخدمين لتنسيقات رقمية وتاريخ صالحة.
* **User Experience / تجربة المستخدم:** Use of `iomanip` for formatted table output and `system("cls")` for clear screen management. / استخدام `iomanip` لإخراج الجداول المنسقة و `system("cls")` لإدارة الشاشة بوضوح.

---

## How It Works / كيفية عمل البرنامج
**English:**
The application operates through a main menu from which users can select various operations.

* **Data Loading:** Upon startup, the system automatically loads existing savings goals from `goals.txt` and transaction records from `transactions.txt` into `std::vector` objects in memory.
* **User Interaction:** Users interact with the system via console input, choosing options like adding goals, adding deposits, viewing reports, or viewing specific goal details.
* **Data Management:** All operations are performed on the `SavingGoal` and `SavingRecord` objects stored in the `std::vector`s.
* **Persistent Saving:** After any significant change (e.g., adding a goal or a deposit), the updated data in memory is saved back to their respective text files (`goals.txt` and `transactions.txt`), overwriting previous content to ensure all changes are permanently stored and available for future sessions.

**العربية:**
يعمل التطبيق من خلال قائمة رئيسية يمكن للمستخدمين من خلالها اختيار عمليات مختلفة.

* **تحميل البيانات:** عند بدء التشغيل، يقوم النظام تلقائياً بتحميل أهداف الادخار الموجودة من `goals.txt` وسجلات المعاملات من `transactions.txt` إلى كائنات `std::vector` في الذاكرة.
* **تفاعل المستخدم:** يتفاعل المستخدمون مع النظام عبر إدخال الأوامر في شاشة الأوامر، واختيار خيارات مثل إضافة أهداف، إضافة ودائع، عرض التقارير، أو عرض تفاصيل هدف معين.
* **إدارة البيانات:** يتم تنفيذ جميع العمليات على كائنات `SavingGoal` و `SavingRecord` المخزنة في `std::vector`s.
* **الحفظ الدائم:** بعد أي تغيير مهم (مثل إضافة هدف أو وديعة)، يتم حفظ البيانات المحدثة في الذاكرة مرة أخرى إلى ملفاتها النصية المعنية (`goals.txt` و `transactions.txt`)، لتحل محل المحتوى السابق لضمان تخزين جميع التغييرات بشكل دائم وتوفرها للجلسات المستقبلية.

---

## Setup and Run / الإعداد والتشغيل
**English:**
To set up and run this project locally, you will need a C++ compiler (like g++ or Visual Studio).

1.  **Clone the Repository:**
    ```bash
    git clone [https://github.com/shahadwalee/Smart-Savings-Tracker-CPP.git](https://github.com/shahadwalee/Smart-Savings-Tracker-CPP.git)
    cd Smart-Savings-Tracker-CPP
    ```
2.  **Compile the Source Code:**
    * **Using g++ (Linux/macOS/MinGW on Windows):**
        Open your terminal or command prompt, navigate to the directory where you saved the file, and run:
        ```bash
        g++ Smart-Savings-Tracker.cpp -o Smart-Savings-Tracker
        ```
        (Make sure you have g++ installed on your system).
    * **Using Visual Studio:**
        Create a new C++ Console Application project in Visual Studio. Add the `Smart-Savings-Tracker.cpp` file to your project. Then, build the solution. Ensure `#define _CRT_SECURE_NO_WARNINGS` is at the top of your `.cpp` file to avoid warnings related to `localtime_s`.
3.  **Run the Executable:**
    * **From Terminal (g++):**
        ```bash
        ./Smart-Savings-Tracker # On Linux/macOS
        Smart-Savings-Tracker.exe # On Windows
        ```
    * **From Visual Studio:**
        Run the compiled executable directly from the Debug/Release folder, or use Visual Studio's Run button (usually F5).

**العربية:**
لإعداد وتشغيل هذا المشروع محلياً، ستحتاج إلى مترجم C++ (مثل g++ أو Visual Studio).

1.  **استنساخ المستودع (Clone the Repository):**
    ```bash
    git clone [https://github.com/shahadwalee/Smart-Savings-Tracker-CPP.git](https://github.com/shahadwalee/Smart-Savings-Tracker-CPP.git)
    cd Smart-Savings-Tracker-CPP
    ```
2.  **ترجمة الكود المصدري (Compile the Source Code):**
    * **باستخدام g++ (لنظام Linux/macOS/MinGW على Windows):**
        افتح الطرفية (terminal) أو موجه الأوامر (command prompt)، انتقل إلى الدليل الذي حفظت فيه الملف، ثم قم بتشغيل الأمر التالي:
        ```bash
        g++ Smart-Savings-Tracker.cpp -o Smart-Savings-Tracker
        ```
        (تأكد من تثبيت g++ على نظامك).
    * **باستخدام Visual Studio:**
        أنشئ مشروع تطبيق وحدة تحكم C++ جديد في Visual Studio. أضف ملف `Smart-Savings-Tracker.cpp` إلى مشروعك. ثم، قم ببناء الحل (build the solution). تأكد من وجود `#define _CRT_SECURE_NO_WARNINGS` في أعلى ملف `.cpp` لتجنب التحذيرات المتعلقة بـ `localtime_s`.
3.  **تشغيل الملف التنفيذي (Run the Executable):**
    * **من الطرفية (g++):**
        ```bash
        ./Smart-Savings-Tracker # على Linux/macOS
        Smart-Savings-Tracker.exe # على Windows
        ```
    * **من Visual Studio:**
        شغل الملف التنفيذي المترجم مباشرة من مجلد Debug/Release، أو استخدم زر التشغيل في Visual Studio (عادةً F5).

---

## Screenshots / لقطات الشاشة
**English:**
Here are visual demonstrations of the Smart Savings Tracker in action:

**العربية:**
فيما يلي عروض مرئية لمتعقب المدخرات الذكي وهو قيد التشغيل:

### 1. Main Menu / القائمة الرئيسية
![Main Menu](https://raw.githubusercontent.com/shahadwalee/Smart-Savings-Tracker-CPP/main/SCREENSHOTS/Main_Menu.png)

### 2. Add New Goal / إضافة هدف جديد
![Add New Goal](https://raw.githubusercontent.com/shahadwalee/Smart-Savings-Tracker-CPP/main/SCREENSHOTS/Goal_Report.png)

### 3. Add Savings Deposit / إضافة وديعة ادخار
![Add Savings Deposit](https://raw.githubusercontent.com/shahadwalee/Smart-Savings-Tracker-CPP/main/SCREENSHOTS/Goal_Details.png)

### 4. View Goals Report / عرض تقرير الأهداف
![View Goals Report](https://raw.githubusercontent.com/shahadwalee/Smart-Savings-Tracker-CPP/main/SCREENSHOTS/Add_GOAL.png)

### 5. View Goal Details / عرض تفاصيل الهدف
![View Goal Details](https://raw.githubusercontent.com/shahadwalee/Smart-Savings-Tracker-CPP/main/SCREENSHOTS/Add_deposit.png)

---
