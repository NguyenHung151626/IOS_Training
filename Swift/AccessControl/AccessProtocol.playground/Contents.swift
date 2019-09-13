import UIKit
//lam banh la nhiem vu bakery, con lai viec chuyen banh nua la ok
//chuyen banh ta phan quyen sang cho shop lam
//chuyển bánh sang cookieShop
struct Cookie {
    var size:Int = 5
}
private protocol BakeryDelegate {
    func cookieWasBaked(_ cookie: Cookie)
}
class Bakery
{
    fileprivate var delegate: BakeryDelegate?
    
    func makeCookie()
    {
        var cookie = Cookie()
        cookie.size = 8
        //đã tạo ra bánh => gọi
        delegate?.cookieWasBaked(cookie)
    }
}
//mỗi khi ông bakery(firstVC) làm xong bánh(firstVC gọi delegate) sẽ gọi ông secondVC
class CookieShop: BakeryDelegate
{
    func cookieWasBaked(_ cookie: Cookie)
    {
        print("Yay! A new cookie was baked, with size \(cookie.size)")
    }
}
let shop = CookieShop()
let bakery = Bakery()
bakery.delegate = shop
//boss goi khi co banh
bakery.makeCookie()
