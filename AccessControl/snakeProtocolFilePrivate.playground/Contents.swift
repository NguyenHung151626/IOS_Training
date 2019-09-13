import UIKit

//đổ xúc sắc + in ra đổ xúc sắc nào (tracker)
//boss đổ xúc sắc
//delegate cho tracker: in ra xúc sắc và số lượt
let finalSquare = 25
var board = [Int](repeating: 0, count: finalSquare + 1)
board[03] = +08; board[06] = +11; board[09] = +09; board[10] = +02
//board[14] = -10; board[19] = -11; board[22] = -02; board[24] = -08
var square = 0
var diceRoll = 0
var soluotdi = 0
////////////////////////////////////////////////////////
private protocol GameDelegate {
    func gameDoDice()
}
class SnakeAndDice {
    fileprivate var delegate: GameDelegate?
    func play() {
        gameLoop: while square != finalSquare {
            diceRoll += 1
            if diceRoll == 7 { diceRoll = 1 }
            delegate?.gameDoDice()
            switch square + diceRoll {
            case finalSquare:
                soluotdi += 1
                // diceRoll will move us to the final square, so the game is over
                break gameLoop
            case let newSquare where newSquare > finalSquare:
                soluotdi += 1
                // diceRoll will move us beyond the final square, so roll again
                continue gameLoop
            default:
                // this is a valid move, so find out its effect
                square += diceRoll
                square += board[square]
                soluotdi += 1
            }
        }
    }
}
class gameTracker: GameDelegate {
    func gameDoDice() {
        print("Roll a Dice \(diceRoll)")
    }
}
var game = SnakeAndDice()
var tracker = gameTracker()
game.delegate = tracker
game.play()
print(soluotdi)



