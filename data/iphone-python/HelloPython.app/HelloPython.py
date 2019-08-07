# Special thanks goes to Dave Arter (dave@minus-zero.org)
# for actually writing most of this sample application!!

# While I managed to get PyObjC working, I didn't actually
# know any Python to go with it ;P. - Jay Freeman (saurik)

import sys

import objc
from _uicaboodle import UIApplicationMain
from objc import YES, NO, NULL
from sqlite3 import dbapi2 as sqlite 

objc.loadBundle("UIKit", globals(), "/System/Library/Frameworks/UIKit.framework")

class PYApplication(UIApplication):
    def getName(self, contact):
        name = contact["first"]
        if contact["last"] is not None:
            name += " " + contact["last"]
        return name

    @objc.signature("i@:@")
    def numberOfSectionsInSectionList_(self, list):
        return len(self.sections_)

    @objc.signature("@@:@i")
    def sectionList_titleForSection_(self, list, section):
        return self.sections_[section]["title"]

    @objc.signature("i@:@i")
    def sectionList_rowForSection_(self, list, section):
        return self.sections_[section]["row"]

    @objc.signature("i@:@")
    def numberOfRowsInTable_(self, table):
        return len(self.contacts_)

    @objc.signature("@@:@i@@")
    def table_cellForRow_column_reusing_(self, table, row, col, reusing):
        contact = self.contacts_[row]
        if reusing is not None:
            cell = reusing
        else:
            cell = UIImageAndTextTableCell.alloc().init()
        cell.setTitle_(self.getName(contact))
        return cell

    @objc.signature("c@:@i")
    def table_canSelectRow_(self, table, row):
        return NO

    @objc.signature("v@:@")
    def applicationDidFinishLaunching_(self, unused):
        self.contacts_ = []
        self.sections_ = []

        db = sqlite.connect(self.userHomeDirectory() + "/Library/AddressBook/AddressBook.sqlitedb")
        cursor = db.cursor()
        cursor.execute("select first, last from ABPerson where first is not null order by first")
        for first, last in cursor.fetchall():
            self.contacts_.append({"first": first, "last": last})
        cursor.close()
        db.close()

        outer = UIHardware.fullScreenApplicationContentRect()
        self.window = UIWindow.alloc().initWithFrame_(outer)

        self.window.orderFront_(self)
        self.window.makeKey_(self)
        self.window.setHidden_(NO)

        inner = self.window.bounds()
        navsize = UINavigationBar.defaultSize()
        navrect = ((0, 0), (inner[1][0], navsize[1]))

        self.view = UIView.alloc().initWithFrame_(self.window.bounds())
        self.window.setContentView_(self.view)

        self.navbar = UINavigationBar.alloc().initWithFrame_(navrect);
        self.view.addSubview_(self.navbar)

        self.navbar.setBarStyle_(1)

        navitem = UINavigationItem.alloc().initWithTitle_("Contact List")
        self.navbar.pushNavigationItem_(navitem)

        i = 0
        letter = u""
        for contact in self.contacts_:
            name = self.getName(contact)
            now = unicode(name[0])
            if letter != now:
                letter = now
                self.sections_.append({"row": i, "title": now})
            i += 1

        lower = ((0, navsize[1]), (inner[1][0], inner[1][1] - navsize[1]));
        self.list = UISectionList.alloc().initWithFrame_(lower)
        self.view.addSubview_(self.list)

        col = UITableColumn.alloc().initWithTitle_identifier_width_("Name", "name", 320)

        table = self.list.table();
        table.setSeparatorStyle_(1)
        table.addTableColumn_(col)
        table.setReusesTableCells_(YES)

        self.list.setDataSource_(self)
        self.list.reloadData()

UIApplicationMain(sys.argv, PYApplication)
