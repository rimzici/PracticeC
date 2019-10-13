//
//  ViewController.swift
//  PracticeC
//
//  Created by Rimnesh Fernandez on 24/08/19.
//  Copyright © 2019 Rimnesh Fernandez. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        print("Hello \(factorial(5))!")
        print("Is 5 even number ? \(isEven(5))!")
        print("Is 10 even number ? \(isEven(10))!")
        testLoopPostInc(3)
        testLoopPreInc(3)
        testMacros(10)
        
        testStatic();
        testStatic();
        
        var cByV = Int32(10);
        var cByR = Int32(10);
        var rescByV = callByValue(cByV);
        var rescByR = callByReference(&cByR);
        print("cByV", cByV);
        print("cByR", cByR);
        print("rescByV", rescByV);
        print("rescByR", rescByR);
        
        testPointers();

        func callbackFunctionSwift() {
            print("inside callbackFunctionSwift");
        }
        triggerCallback(callbackFunctionSwift);
        let n = "/rimz.db";
        let documentsPath = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true)[0];
        let d = strdup(documentsPath+n);
        insertStudentRecord(d);
        
        var sample = [Int32(1), Int32(2), Int32(5), Int32(10), Int32(4), Int32(22)];
        var int6Pointer = UnsafeMutablePointer<Int32>.allocate(capacity: 6);
        int6Pointer.initialize(from: &sample, count: 6)
        deleteArrayItem(int6Pointer, 6, Int32(5));
        arraySort();
        findMaxMin();
        reverseArray();
        mergeArray();
    }
}

