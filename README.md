# Mixin and CRTP
사실 이 두가지는 비교대상은 아닌 듯하다.

## 1번 레퍼런스 내용 정리
CRTP와 Mixin의 설명이 반대로 적혀있는 것 같아 교차하여 작성하였다.
### Curiously Recurring Template Pattern(CRTP)
- 원본 클래스의 선언부를 건드려야한다.
- 클라이언트 코드에서 원본 클래스를 직접 사용해야 한다.

### MixIn
- 원본 코드를 건드리지 않는다.
- 클라이언트 코드에서 원본 코드를 직접적으로 사용하지 않는다.
- 기능을 확장하기 위해서는 minin wrapping 클래스를 만들어야 한다.
- virtual 소멸자가 없더라도, 원본 클래스로 부터 상속받아야한다. 이럴 경우 mixin 클래스가 원본 클래스에 대해 다형성을 사용하여 삭제되면 안된다.

## 2번 레퍼런스 내용 정리
### CRTP
- 게으르다.
    - template의 특징으로 사용되지 않는 함수는 인스턴스화 되지 않는다.
- 정적 다형성을 가진다.
    - template 인자로 static_cast함으로써 정적다형성을 구현

### Mixin
- python에서 다중상속을 하고있는 클래스의 행동을 변경핼 때 주로 이용되는 테크닉이다.
- C++에서는 CRTP를 이용해서 Minin을 구현할 수 있다.
- Mixin의 예제로 std::enable_shared_from_this가 있다.
    - 자기 자신의 클래스를 템플릿 인자로 넘겨주어야 함
    - shared_from_this() 함수를 사용할 수 있음

## Wiki에서의 정의
OOP에서 Mixin은 다른 클래스에서 사용하기 위한 메소드를 포함하는 클래스이다 (다른 클래스의 부모가 될 필요가 없다). 따라서 상속보다는 포함관계로 주로 표현된다. Mixin은 다중상속의 다이아몬드 문제를 피하거나 프로그래밍 언어에서 다중상속 지원이 부족한 경우 주로 사용된다. 또한, Mixin은 method가 구현된 interface로 간주할 수도 있다.

## Reference
 1. https://www.fluentcpp.com/2017/12/12/mixin-classes-yang-crtp/
 2. https://www.modernescpp.com/index.php/c-is-still-lazy
