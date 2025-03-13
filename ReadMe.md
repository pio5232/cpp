# 윤성우의 열혈 C++ 코드
기본 개념 / 예제 및 기억할 것들을 메모
---
## 1. C언어 기반의 C++
* 입출력
* 함수 오버로딩   
  * 함수 호출 시 전달되는 인자를 통해 호출하고자 하는 함수의 구분이 가능 (C와 달리 C++은 **함수의 이름 + 매개변수의 선언**)으로 호출할 함수를 찾는다.
* 매개변수의 디폴트 값 (Default Value)
  * 함수의 선언 부분에만 표현
- 인라인 함수
  - 매크로 함수의 대표적인 장/단점은
    - 일반적인 함수에 비해서 실행 속도가 빠르다 <-> 정의하기가 어려우며, 복잡한 함수를 매크로의 형태로 정의하기 어렵다.
    - 또한 매크로를 이용한 함수의 인라인화는 **전처리기**에 의해서 처리
    - 매크로 함수를 이용하면 자료형에 의존적이지 않은 함수를 만들 수 있으나, template을 활용하면 이러한 단점도 상쇄시킬 수 있다.
  - 인라인 함수는 이런 장점을 유지하되 / 단점은 제거한 상태로 사용.
  - inline 키워드를 이용한 함수의 인라인화는 **컴파일러**에 의해서 처리.
  - 또한 컴파일러는 성능에 해가 된다고 판단할 경우 inline 키워드를 무시할 수 있다.
- 이름 공간 (namespace)
  - 서로 다른 프로젝트에서의 같은 이름 충돌을 방지하기 위해서 사용 
  - :: ( 범위 지정 연산자 )를 이용해 접근
    - 또한 ::의 역할은 지역 변수와 전역 변수가 같은 이름을 가질 때 ::을 이용해 전역 변수에 접근을 할 수 있음.

---
## 2. C언어 기반의 C++ (2)
- 참조자
  - 변수에 대해서만 선언이 가능하며, 선언됨과 동시에 누군가를 참조해야만 한다.
  - const 변수에 대한 참조는 const Reference로 받아야 한다.
- Call by value / Call by Reference
  - Call by value 
    - ( 값을 인자로 전달하는 함수의 호출 방식 )
  - Call by Reference
    - ( 주소 값을 전달받아서 함수 외부에 선언된 변수에 접근하는 형태의 함수 호출 방식 )
- 참조자와 const
  - 참조자로 매개변수를 받고 데이터의 변경을 하지 않을 때는 **(const Type& param)** 형태로 받음으로써 데이터의 변경을 하지 않겠다고 선언

- malloc / free <-> new / delete
  - 동적 메모리 할당 방식
  - new / delete 는 객체 대상으로 메모리 할당 후 생성자 호출 / 메모리 해제 전 소멸자 호출을 해주는 것이 malloc / free와 다른 점
  
- C++ 프로젝트에서 C 헤더가 아닌 C++의 헤더를 선언해야 하는 이유.
  - C++ 표준 라이브러리 제공 함수들과 C 표준 라이브러리가 제공하는 함수들이 완전히 일치하는 것은 아님. C++문법을 기반으로 개선된 형태의 라이브러리가 구현되어 있기 때문에 가급적이면 C++ 표준 헤더를 이용하자.

---
## 3. 클래스의 기본
- 특정 자료형에 국한되는 상수들은 클래스 내에 또는 따로 분리된 namespace에 enum으로 정의
- 클래스 내에 함수가 정의되어 있으면 (선언과 정의를 동시에 하는 경우) **함수를 인라인으로 처리하라**는 의미가 있음
- C++에서 class와 struct의 차이는 기본 접근 제한자가 private이냐, public이냐의 차이.
- 인라인으로 선언한 함수는 정의까지 헤더파일에 함께 넣어야 한다.
  - 인라인의 의미를 생각하면 **"컴파일 과정에서 함수의 호출 문이 있는 곳에 함수의 코드가 삽입**되어야 하기 때문이다.
---
## 4. 클래스의 완성
- 정보 은닉 (Information Hiding)
  - 멤버 변수를 private으로 선언, 해당 변수를 접근하는 함수를 별도로 정의 -> 안전한 형태로 멤버 변수의 접근을 유도하는 것
- const 함수
  - 함수 명 const 
  - 1. **이 함수 내에서는 멤버 변수의 값을 변경하지 않겠다**는 의미
  - 2. const가 아닌 함수의 호출을 막는다. 즉 const 함수는 const 함수만을 호출할 수 있다.
    - 코드의 안전성을 높이는 효과가 있음.
- 캡슐화 (Encapsulation)
  - **정보 은닉의 개념 + 관련 있는 함수와 변수를 하나의 클래스 안에 묶는 것 (여러가지 작업을 하나의 틀로 묶어서 처리할 수 있도록 하는)**
  
- 생성자 (Constructor)
  - 매개변수 없는 생성자의 경우
    - class instance(); 와 같은 생성은 **함수의 원형을 선언하는 것으로 취급**되기 때문에 class instance; 와 같이 사용하도록 한다.
  - private 생성자
    - 클래스 내부에서 객체의 생성을 허용하는 목적으로는 생성자를 private하게 설정함.

- 멤버 이니셜라이저 (Member Initializer)
  - 상속 간 base의 생성자를 호출하거나, 생성자 호출 과정에서 객체 멤버의 초기화를 진행시킬 때 사용.
  ```cpp
  class TestClass
  {
    public:
    TestClass() : instances..n(..params) {}
    private:
    Other1 instance1;
    Other2 instance2;
  }

  ```
  - 생성자 함수 내부에서 객체를 초기화 하는 것은 
    - 객체 생성자 호출 (임시 객체 생성) -> = (대입 연산자)를 통한 복사가 이루어지는데
    - **멤버 이니셜라이즈를 사용할 경우 직접 생성자를 호출**하므로 불필요한 작업이 사라진다.
    - 즉, 멤버 이니셜라이즈를 활용하는 경우 **선언과 동시에 초기화가 이뤄지는 형태로 바이너리 코드가 생성**된다.

- this 포인터
  - this 포인터를 이용해 **Self-Reference (자기 자신의 참조자)**를 반환할 수 있다.

--- 
- C++ 스타일의 초기화
  - 다음과 같은 방식으로 변수와 참조자를 선언 및 초기화가 가능하다
    - int num = 20; => int num(20);
    - int &ref = num; => int &ref(num); 
## 5. 복사 생성자
- explicit 키워드를 통해 암묵적 형변환을 제한할 수 있음 
```cpp
class MyClass
{
private:
	int num1;
	int num2;
public:
	explicit MyClass(int n1, int n2) : num1(n1), num2(n2) {}
	explicit MyClass(MyClass& copy) : num1(copy.num1), num2(copy.num2){}
}

MyClass my = {10,20}; 
// explicit 키워드 없이는 암묵적으로 MyClass My(10,20)으로 변환되어 성공적으로 수행된다.

MyClass my2 = my
// 이것도 마찬가지로 explicit 키워드 없이는 MyClass my2(my)로 암묵적인 변환이 일어나 수행된다.

//생성자에 explicit 키워드가 존재하면 이런 암묵적인 변환에 의한 초기화를 막는다.
```
###  **explicit 키워드의 사용은 코드의 명학함을 더하기 위해 자주 사용된다.**
<br></br>

- 복사 생성자 또는 대입 연산자를 이용할 때는 포인터 멤버에 대해서 **깊은 복사 / 얕은 복사 처리를 주의**
- 복사 생성자의 호출 시점
  - 1. 기존 생성된 객체를 이용해서 생성되 객체를 초기화하는 경우
  - 2. 함수에 참조가 아닌 Call-by-value 형식으로 객체를 전달하는 경우
  - 3. 함수의 리턴이 참조가 아닌 객체를 반환하는 경우.

- 임시 객체
  - 말 그대로 임시로 생성되는 객체 (함수에서 객체를 참조가 아닌 형태로 반환 / 인자로 받을 때에도 생성됨)
  - const Temp& ref = 객체반환함수 를 했을 때
    - 반환 함수에서는 객체를 만들고 그대로 자신의 포인터를 반환
    - 이렇게 참조자에 사용된 임시 객체는 바로 소멸하지 않고, 참조자의 생명 주기에 맞춰서 소멸된다.
    - **const & 참조로 받기 때문에 임시 객체의 수명이 연장된다.**
---
## 6. friend와 static 그리고 const
- const 객체와 const 객체의 특성
  - const 객체도 마찬가지로 존재.
    - 멤버 변수의 변경을 허용하지 않는다.
    - const 함수만 호출 가능

- friend 클래스
  - A클래스에서 friend class B 선언 => B클래스에서는 A클래스에 접근을 할 수 있다.
  - 함수의 friend 선언
    - A 클래스 , B 클래스 존재
    - B 클래스에서 A 클래스의 함수에 대해서 friend 선언
  ```CPP
  class A
  {
  public:
     void Add(const B& b1,const B& b2);
  }

  class B
  {
  private:
    int x;
    int y;
  public:
    friend void A::Add(const B& b1, const B& b2);
  };
  => A의 Add 함수에서는 B의 x,y멤버에 접근이 가능하다. 
  // 어떤 클래스에서 friend ~ 선언 : some 클래스 / 함수 에서 내 정보를 사용하는 것을 허락할게~~ 라고 생각

  ```
  - friend 선언 ? 웬만하면 사용하지 말도록 하자. (정보 은닉을 무너뜨리는 문법)

- C++에서의 static
  - 기존 C의 static
    - static 전역 변수
      - 선언된 cpp에서의 참조만 허용하겠다.
    - 함수 내에 선언된 static
      - 한 번먼 초기화되고, 지역변수와 달리 함수를 빠져나가도 소멸되지 않는다. 
      - 전역 변수와 마찬가지로 초기화하지 않으면 0으로 초기화된다.
  - static 멤버 변수
    - 메모리 할당 시점은 전역 변수와 같으나,처음 사용될 때 초기화된다.
    - 헤더에 static 멤버를 선언했다면 cpp에서 Class::Static 멤버를 통해 따로 초기화 값을 정의해주도록 해야한다.
  - static 멤버 함수
  - const static 멤버
    - static 멤버의 초기화는 이니셜라이즈를 해야하지만 **const static 멤버의 초기화는 선언과 동시**에 하는 것이 가능하다.

- mutable 키워드
  - 이 키워드가 붙은 멤버 변수는 **const 함수 내에서의 값 변경을 예외적으로 허락**한다.
  - mutable은 아주 제한적으로, 예외적인 경우에 한해서만 사용하는 키워드이다.
---
## 7. 상속 (Inheritance)
- Base 클래스와 Derived 클래스의 생성자 / 소멸자 호출 
  - https://velog.io/@jhmv7mp/s
- public / protected / priavte 상속
  - Derived 클래스는 Base 클래스의 멤버를 접근 제한자 형태로 상속받아서 가지겠다! 라는 의미
  ```CPP
  class Base
  {
    private:
        int x;
    protected:
        int y;
    public:
        int z;
  }

  class Derived : private Base
  => 
  class Derived 
  {
      // x는 Base의 private => 접근 불가
      // y는 private y;의 형태 => 접근 가능
      // z는 private z;의 형태 => 접근 가능
  }

  class Derived2 : protected Base
  {
     // x는 Base의 private => 접근 불가
     // y는 protected y;의 형태 => 접근 가능
     // z는 protected z;의 형태 => 접근 가능
  }

  class DDerived2 : public Derived
  {
     // DDerived2는 private x, protected y, protected z를 상속
     // x는 Base의 private => 접근 불가
     // y는 protected y;의 형태 -> 접근 가능 
     // z는 protected z;의 형태 -> 접근 가능.
  }

  // 만약 
  class DDerived3: private Derived
  {
     // 로 받았더라도 
     // x는 Base의 private => 접근 불가
     // y는 자신의 private y;의 형태 -> 접근 가능 
     // z는 자신의 private z;의 형태 -> 접근 가능.
  }
  // 으로 DDerived3을 다음에 상속받는 클래스는 모든 멤버를 사용할 수 없다. (어떻게 받든 이미 모든 멤버가 private형태이기 때문에)


  ```

  ---
  ## 8.상속과 다형성  
- base 클래스의 포인터로 derived 클래스 객체를 가리킬 수 있음.

- 상속을 하는 이유
  - 상속을 통해 관련된 클래스들에 대한 일관적인 규약을 마련할 수 있음.
  
- 순수 가상 함수
  - 함수의 몸체가 정의되지 않은 함수,순수 가상 함수를 가지는 클래스는 객체 생성이 불가능함
  - 객체 생성이 목표가 아닌 인터페이스 정의를 위해 존재하는 클래스에 사용 - 이를 추상 클래스라고 함
    - 잘못된 객체의 생성을 막을 수 있음

- 다형성 (Polymorphism)
  - 모습은 같은데 형태는 다르다.
    - Overloading / Overriding

- 가상 소멸자가 필요한 이유
  - Base* b = new Derived()의 형태로 사용 후 소멸할 때
    -  **Base의 소멸자만 호출 -> Derived의 소멸자**는 호출이 되지 않는다.
    - => MEMORY LEAK 의 원인이 된다.
      - 그러므로 상속 관계에서는 virtual을 통해 소멸자를 만들어주자

- 참조자의 참조 가능성
  - Base* b = new Derived()와 같이
    - Derived d; <br/>Base& rb = d; 로도 사용할 수 있으며 사용법은 동일하다.

---
## 9. 가상 (virtual)의 원리와 다중 상속
- 멤버 함수의 실행
```cpp
#include <iostream>
using namespace std;

typedef struct Data
{
	int data;
	void (*ShowData)(Data*);
	void (*Add)(Data*, int);
} Data;

void ShowData(Data* THIS) { cout << "Data : " << THIS->data << endl; }
void Add(Data* THIS, int num) { THIS->data += num; }

int main()
{
	Data obj1 = { 15, ShowData, Add };
	Data obj2 = { 7, ShowData, Add };

	obj1.Add(&obj1, 17);
	obj2.Add(&obj2, 9);

	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);

	return 0;
}
```
이와 같이 멤버 함수는 객체들이 공유하는 형태

- 가상 함수의 동작 원리와 가상함수 테이블
  - https://velog.io/@jhmv7mp/s

- 다중 상속의 문제
  - 두 기초 클래스에 동일한 이름의 멤버가 존재하는 경우  
    - 가상 상속을 통해 해결
      - 가상 상속을 통해 겹치는 멤버 변수 / 멤버 함수 등에 대한 상속을 1번으로 하게끔 한다.


---
## 10. 연산자 오버로딩
- 'operator' 키워드와 '연산자' 를 묶어서 함수 이름을 정의하면 **함수 이름을 이용한 호출 / 연산자를 이용한 호출** 2가지를 허용
-  똑같은 대상에 대해서 연산자 오버로딩을 했을 때 
   -  전역 함수 / 멤버 함수에 연산자 오버로딩을 했을 때 멤버 함수에서 오버로딩된 연산자가 먼저 호출된다.
   
- 단항 연산자 오버로딩 (++, --)
  - 전위 operator++() / 후위 operator++(int)
  - 전위에서 객체 자신의 참조자를 반환하는 이유 -> **연속된 형태의 연산이 가능하게 하기 위해서 ex) ++(++my)**

- 반환 형에서 const 선언과 const 객체
```cpp
class Point
{
  private:
  int xpos;
  int ypos;
  ...
  const Point operator++(int)
	{
		const Point retobj(xpos, ypos);
		xpos += 1;
		ypos += 1;
		return retobj;
	}
}

// 함수가 반환될 때는 어차피 복사되기 때문에 의미가 없음

Point point(10,20);
(point++)++; 
// 문법적으로 cosnt 객체를 반환 => 위 코드와 같은 형태의 코드의 실행을 막기 위해서.
```

- 교환 법칙 성립을 위한 구현
  - 멤버 함수 형태로 정의하는 것은 객체가 왼쪽에 오는 버전 1개다. => 다른 1개는 전역 함수 형태로 구현하도록 한다.

```cpp
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{

	}

	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point operator*(int times)
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}

};

Point operator*(int times, Point& ref)
{
	return ref * times; 
  // times * ref 로 변경하면 이 함수의 무한 호출 => 스택 오버플로우가 발생한다.
}
```
## 연산자 오버로딩 2

- default 대입 연산자의 문제점
```cpp
class Test
{
  private: 
      char * name;
  public:
      Test(const char* tName)
      {
          int len = strlen(tName) + 1;
          name = new char[len];
          strcpy(name, tName);
      }
      ~Test()
      {
        delete[] name;
      }
}

int main()
{
	Person man1("aaa");
	Person man2("bbb");

  man1 = man2;
	return 0;
}
```
    - 문제 1. man2가 가지고 있던 포인터는 해제할 수 없는 상황이 됨 (man2의 name은 man1의 name과 동일한 대상을 가리키고 있음)
    - 문제 2. 해제 시점에 man1에서 delete, man2에서 delete => double free에러가 발생.
    

- 상속 구조에서의 대입 연산자 호출
  - Base / Derived 클래스에서 대입 연산자를 호출할 때
```cpp
class Base
{
  public:
    Base& operator=(const Base& other)
    {
        cout << "Base operator=() \n";
        reutrn *this;
    }
}

class Derived : public Base
{
  public:
  Derived& operator=(const Derived& other)
  {
      // Derived의 operator를 정의한 상태에서 Base의 operator를 호출하고 싶다면
      Base::operator=(other);

      cout << "Derived operator=() \n";
      return *this;
  }
}

int main()
{
  Derived d1,d2;
  ...
  d1 = d2;
  
  // Derived operator=를 정의하지 않음 => Base operator= 실행
  // Derived operator=를 정의         => Derived operator= 실행
  
}
```

- 이니셜라이저는 성능 향상을 위해 도움을 준다.
  - 위에서 말한 바와 같다.
  - 객체 초기화
    - 멤버 초기화 이니셜라이저를 통하면 **생성과 동시에 초기화**를 한다.
    - {}안에서 초기화를 하는 것은 **생성 + 대입** 2가지 작업이 진행된다.
```cpp
#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA(int n = 0) : num(n)
	{
		cout << "AAA(int n = 0)" << endl;
	}
	AAA(const AAA& ref) : num(ref.num)
	{
		cout << "AAA(const AAA& ref)" << endl;
	}
	AAA& operator=(const AAA& ref)
	{
		num = ref.num;
		cout << "operator= (const AAA& ref) " << endl;
		return *this;
	}
};

class BBB
{
private:
	AAA mem;
public:
	BBB(const AAA& ref) : mem(ref) {}
};

class CCC
{
private:
	AAA mem;
public:
	CCC(const AAA& ref) { mem = ref; }
};

int main()
{
	AAA obj1(12);
	cout << "***********************" << endl;
	BBB obj2(obj1);
	cout << "***********************" << endl;
	CCC obj3(obj1);

	return 0;
}
```

- 배열의 인덱스 연산자 오버로딩
  - operatr[] 를 오버로딩하여서 사용한다.
  

- new / delete 오버로딩
  - new 
    - 오버로딩된 new 연산자는 기본 new 연산자의 모든 부분을 대체하지 않음
      - 1. **메모리 할당 -----------------------------> 이 부분만 오버로딩 가능**
      - 2. 생성자 호출  
      - 3. 자료형에 맞게 주소 값의 형 변환 
      - 2번과 3번에 대한 진행은 컴파일러가 알아서 진행하도록 만들어놓는다..

  - delete
    - delete 도 마찬가지로 메모리 해제하는 부분만 오버로딩
    -  1. **소멸자 호출 ------- 이 부분만 오버로딩**
    -  2. 메모리 해제 => 컴파일러가 진행
  

  - new / delete는 static 함수
    - **멤버 함수로 선언 => 그 클래스 객체에 대해서만 오버로딩된 new를 호출**
  
  - 기본적인 new / delete 함수
    - void* operate new (size_t size)
    - void* operate new[] (size_t size)
    - void delete (void* ptr)
    - void delete[] (void* ptr)

- 포인터 연산자 오버로딩 ( * , -> )
  - 둘 다 피연산자가 하나인 단항 연산자의 형태
  - *는 객체 자신을 반환하는 형태로
  - ->는 객체 자신의 포인터를 반환하는 형태로!


- ()연산자 오버로딩과 펑터(Functor)
  - 객체를 함수처럼 사용
  - 왜 이걸 사용 ?
    - 객체 또는 함수의 동작 방식에 유연함을 제공할 때 주로 사용된다.
    - (알고리즘에서 정렬 방식을 정한다든가..)


```cpp
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{
	}

	Point operator+(const Point& point) const
	{
		return Point(xpos + point.xpos, ypos + point.ypos);
	}
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<< (ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class Adder
{
public:
	int operator() (const int& n1, const int& n2)
	{
		return n1 + n2;
	}

	double operator()(const double& e1, const double& e2)
	{
		return e1 + e2;
	}

	Point operator()(const Point& pos1, const Point& pos2)
	{
		return pos1 + pos2;
	}
};
int main()
{
	Adder adder;
	cout << adder(1, 3) << endl;
	cout << adder(1.5, 3.8) << endl;
	cout << adder(Point(3,4), Point(7,9)) << endl;
}
```

- 형 변환 연산자
  - operator type () { 구현 }
```cpp
class Number
{
private:
	int num;
public:
	operator int()
	{
		return num;  // -> 반환값 형식은 맞춰줘야한다.
	}
};

int main()
{
	Number num1;
	Number num2 = num1 + 20; => // num1이 int형으로 변환-> Number num2 = 50과 동일
	return 0;
}
```
---
## 13. Template
- 템플릿으로 정의된 함수는 **컴파일 타임**에 컴파일러가 각 타입의 함수를 만든다.
- 함수 템플릿과 템플릿 함수
```cpp
#include <iostream>
using namespace std;

template <typename T>
T add(T num1, T num2)   // ------- 함수의 원형을 정의 -> 함수 템플릿
{
	return num1 + num2;
}

// main에서 add<int>, add<double> 의 함수가 다음과 같이 생성이 된다
// int add(int num1, int num2) {return num1 + num2;}
// double add(double num1, double num2) {return num1 + num2;}
// 이렇게 템플릿 기반으로 만들어진 함수를 템플릿 함수라고 한다.

int main()
{
	cout << add<int>(15, 20) << endl;
	cout << add<double>(2.9, 3.7) << endl;
	cout << add<int>(3.2, 3.2) << endl;
	cout << add<double>(3.14,2.75) << endl;

	return 0;
}

```

- 또한 이름이 같은 template 함수와 일반 함수는 함께 존재할 수 있지만
실행 순서는 일반 함수 > template 함수이다.

```cpp
template <typename T>
T add(T num1, T num2)
{
	cout << "T add()\n";
	return num1 + num2;
}

int add(int num1, int num2)
{
	cout << "int add()\n";
	return num1 + num2;
}

double add(double num1, double num2) 
{
	cout << "double add()\n";
	return num1 + num2;
}


int main()
{
	cout << add(15, 20) << endl;   // --- int add()
	cout << add(2.9, 3.7) << endl; // --- double add()
	cout << add<int>(3.2, 3.2) << endl; // --- template<int>
	cout << add<double>(3.14, 2.75) << endl; // --- template<double>

	return 0;
}
```

- 함수 템플릿 특수화
  - template <> 형태로 사용
- 클래스 템플릿의 특수화
```cpp
기본 template 클래스
template <typename T>
class c

// ------------------------------------------- 클래스 템플릿의 특수화  --------------------
template <>
class c<type>

// ------------------------------------------- 템플릿의 부분 특수화    --------------------
template<typename T>
class c<T, int> // int는 고정

// ------------------------------------------- 템플릿 인자             --------------------
 템플릿의 매개변수에는 변수의 선언이 올 수 있으며, 디폴트 값으로도 지정이 가능하다.

template<typename T = int, int len = 7>
class c
{
  private: T arr[len];
  ...
}

c<> myclass; // ==> 이 코드는 c<int, 7> myclass와 동일하다.


=> 이렇게 만들면 c<int, 5>와 c<int, 7> 은 다른 타입이 되기 때문에
대입 및 복사에 대한 부분은 신경 쓸 필요가 없음, 불필요한 코드가 없어도 된다.



// ------------------------------------------- 템플릿의 static 변수     --------------------

- template 클래스의 static
  - static 지역 변수 / static 멤버 변수 모두 만들어지는 클래스 각각에 따라 따로 관리됨

template <typename T>
class MyClass
{
  static T member;
}

template <typename T>
T MyClass<T>::member = 0;

=> MyClass<int>의 member와 MyClass<double> 의 멤버는 따로 관리된다는 말이다.

또한 템플릿 static 멤버 변수 초기화의 특수화도 다음과 같은 형태로 가능하다

template <>
long MyClass<T>::member = 13532;


```


- 템플릿을 분리할 경우 헤더 파일만을 참조할 때는 실제 그 클래스 / 함수의 정의를 알 수 없기 때문에 링크 에러가 발생
  - => 템플릿 함수의 선언과 정의를 헤더 파일에 한번에 구현하거나 / template을 참조하는 쪽에서 실제 헤더 파일 + 정의가 구현된 cpp파일까지 include해야한다.

