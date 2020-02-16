//
//  ViewController.swift
//  PracticeC
//
//  Created by Rimnesh Fernandez on 24/08/19.
//  Copyright © 2019 Rimnesh Fernandez. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var nameone: UITextField!
    
    @IBOutlet weak var nametwo: UITextField!
    
    
    @IBOutlet weak var relationlabel: UILabel!
    
    @IBAction func submitButton(_ sender: UIButton) {
        
        relationlabel.text = getRelation(nameone.text ?? "", nametwo.text ?? "");
    }
    
    func getRelation(_ nameOne: String,_ nameTwo: String) -> String {
        if (nameOne == "") {
            return "name one is empty"
        }
        if (nameTwo == "") {
            return "name two is empty"
        }
        
        var n1 = nameOne.lowercased(), n2 = nameTwo.lowercased()
       for (index, char) in n1.enumerated() {
        let fi = n2.firstIndex(of: char)
        if (fi != nil) {
            n1.removeAll(where: { char == $0})
        }
        n2.removeAll(where: { char == $0})
       }
        n1.removeAll(where: { " " == $0 })
        n2.removeAll(where: { " " == $0 })

        let fCount = n1.count + n2.count;

        let REL = ["F","L","A","M","E","S"]
        var FINAL_EXCLUDED_COUNT = REL.count - 1;
        var EXCLUDED = [String]();
        
        var counter = 0;
        while (EXCLUDED.count != FINAL_EXCLUDED_COUNT) {
            for index in 0...(REL.count - 1) {
                if (!EXCLUDED.contains(REL[index])) {
                    counter+=1;
                    if (counter == fCount) {
                        EXCLUDED.append(REL[index])
                        counter = 0;
                    }
                }
            }
        }

        var FOUND = ""
        for index in 0...(REL.count - 1) {
            if (!EXCLUDED.contains(REL[index])) {
                FOUND = REL[index];
                break;
            }
        }

        switch(FOUND) {
            case "F":
                return "FRIENDS";
            case "L":
                return "LOVERS";
            case "A":
                return "AFFECTIONATE";
            case "M":
                return "MARRIAGE";
            case "E":
                return "ENEMIES";
            case "S":
                return "SIBLINGS";
            default:
                return "ALIENS!!";
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        nameone.delegate = self
        nametwo.delegate = self
        

//        LessonsC();
    }
    
    func LessonsC() {
        //        print("Hello \(factorial(5))!")
        //        print("Is 5 even number ? \(isEven(5))!")
        //        print("Is 10 even number ? \(isEven(10))!")
        //        testLoopPostInc(3)
        //        testLoopPreInc(3)
        //        testMacros(10)
        //
        //        testStatic();
        //        testStatic();
                
                var cByV = Int32(10);
                var cByR = Int32(10);
                var rescByV = callByValue(cByV);
                var rescByR = callByReference(&cByR);
                print("cByV", cByV);
                print("cByR", cByR);
                print("rescByV", rescByV);
                print("rescByR", rescByR);
                
                testPointers();
                learnDynamicMemAllocation();

        //        func callbackFunctionSwift() {
        //            print("inside callbackFunctionSwift");
        //        }
        //        triggerCallback(callbackFunctionSwift);
        //        let n = "/rimz.db";
        //        let documentsPath = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true)[0];
        //        let d = strdup(documentsPath+n);
        //        insertStudentRecord(d);
        //
        //        var sample = [Int32(1), Int32(2), Int32(5), Int32(10), Int32(4), Int32(22)];
        //        var int6Pointer = UnsafeMutablePointer<Int32>.allocate(capacity: 6);
        //        int6Pointer.initialize(from: &sample, count: 6)
        //        deleteArrayItem(int6Pointer, 6, Int32(5));
        //        arraySort();
        //        findMaxMin();
        //        reverseArray();
        //        mergeArray();
    }
}

extension ViewController: UITextFieldDelegate {
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return true
    }
}
