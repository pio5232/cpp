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
    friend void B::Add(const B& b1, const B& b2);
  }

  => A의 Add 함수에서는 B의 x,y멤버에 접근이 가능하다. 
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