import UIKit

struct TrackedString {
    private(set) var numberOfEdits = 0
    var value: String = "" {
        didSet {
            numberOfEdits += 1
        }
    }
}
var stringToEdit = TrackedString()
stringToEdit.value = "This string will be tracked."
stringToEdit.value += " This edit will increment numberOfEdits."
stringToEdit.value += " So will this one."
//can getter but no setter: private prevents both
print("The number of edits is \(stringToEdit.numberOfEdits)")
// Prints "The number of edits is 3"
//stringToEdit.numberOfEdits = 10           => Error
print("The number of edits is \(stringToEdit.numberOfEdits)")

