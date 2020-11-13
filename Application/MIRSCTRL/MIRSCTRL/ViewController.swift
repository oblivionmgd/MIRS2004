//
//  ViewController.swift
//  MIRSCTRL
//
//  Created by 中村伸哉 on 2020/11/06.
//

import UIKit
import Firebase

class ViewController: UIViewController {
    var ref: DatabaseReference!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        ref = Database.database().reference()
    }
}

