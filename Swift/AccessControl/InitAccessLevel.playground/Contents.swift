import UIKit

//khởi tạo coaches và điểm hiện tại ko thay đổi
class Coach {
    
    private var str : String
    private var number: Int
    init(s: String, n: Int) {
        str = s
        number = n
    }
    func getName() -> String {
        return str
    }
    func getPoint() -> Int {
        return number
    }
}

class CompareCoach {
    private var tuple : (Coach, Coach)
    init(f1: Coach, f2: Coach) { //compiler error.
        tuple = (f1, f2)
    }
    func getValues() -> (String, String) {
        return (tuple.0.getName() + " / " + tuple.1.getName(), "\(tuple.0.getPoint())    / \(tuple.1.getPoint())")
    }
}
let compareCoach = CompareCoach(f1: Coach(s: "Sir Alex",n: 103), f2: Coach(s: "Zidane",n: 101))
print(compareCoach.getValues().0)
print(compareCoach.getValues().1)
let someCoach = Coach(s: "Solskjær", n: 101)
let anotherCoach = Coach(s: "Josep Guardiola", n: 101)
let anotherCompareCoach = CompareCoach(f1: someCoach, f2: anotherCoach)
print(anotherCompareCoach.getValues().0)
print(anotherCompareCoach.getValues().1)
print(anotherCoach.getName())
print(anotherCoach.getPoint())
//init cần kín hơn kiểu mà nó khởi tạo => chọn internal, fileprivate
