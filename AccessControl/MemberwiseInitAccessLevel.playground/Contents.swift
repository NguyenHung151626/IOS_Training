import UIKit

struct Box {
    let type: String
    private var color: String = "red"
    var width = 0.0, height = 0.0
    init(type: String, color: String, width: Double, height: Double) {
        self.type = type
        self.color = color
        self.width = width
        self.height = height
    }
}
let boxGreen = Box(type: "USSmall", color: "green", width: 10, height: 10)
let boxRed = Box(type: "Vietnam", color: "red", width: 5, height: 5)
print(boxGreen.type)
print(boxGreen.width)
print(boxRed.type)
print(boxRed.width)
