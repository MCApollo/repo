import obc.*;
import joc.*;

import joc.Message;

import static joc.Pointer.*;
import static joc.Static.*;

import java.util.ArrayList;
import java.util.Date;

public class HelloJava
    extends UIApplication
{

private UIWindow window;

private static class Contact {
    public String first;
    public String last;

    public Contact(String first, String last) {
        this.first = first;
        this.last = last;
    }

    public String getName() {
        String name = first;
        if (last != null)
            name += " " + last;
        return name;
    }
}

public static class Section {
    public int row;
    public String title;

    public Section(int row, String title) {
        this.row = row;
        this.title = title;
    }
}

private ArrayList<Contact> contacts_;
private ArrayList<Section> sections_;

@Message int numberOfSectionsInSectionList$(UISectionList list) {
    return sections_.size();
}

@Message String sectionList$titleForSection$(UISectionList list, int section) {
    return sections_.get(section).title;
}

@Message int sectionList$rowForSection$(UISectionList list, int section) {
    return sections_.get(section).row;
}

@Message int numberOfRowsInTable$(UITable table) {
    return contacts_.size();
}

@Message UITableCell table$cellForRow$column$reusing$(UITable table, int row, UITableColumn col, UITableCell reusing) {
    Contact contact = contacts_.get(row);

    UIImageAndTextTableCell cell;
    if (reusing != null)
        cell = (UIImageAndTextTableCell) reusing;
    else
        cell = (UIImageAndTextTableCell) new UIImageAndTextTableCell().init();

    cell.setTitle$(contact.getName());
    return cell;
}

@Message public byte table$canSelectRow$(UITable table, int row) {
    return NO;
}

@Message public void applicationDidFinishLaunching$(Object unused)
    throws Exception
{
    System.out.println("work");
    contacts_ = new ArrayList<Contact>();
    sections_ = new ArrayList<Section>();

    SQLite.Database ab = new SQLite.Database();
    ab.open(userHomeDirectory().toString() + "/Library/AddressBook/AddressBook.sqlitedb", 0666); try {
        SQLite.Stmt st = ab.prepare("select first, last from ABPerson where first is not null order by first"); try {
            while (st.step())
                contacts_.add(new Contact(
                    st.column_string(0),
                    st.column_string(1)
                ));
        } finally { st.close(); }
    } finally { ab.close(); }

    CGRect outer = UIHardware.$fullScreenApplicationContentRect();
    window = new UIWindow().initWithContentRect$(outer);

    window.orderFront$(this);
    window.makeKey$(this);
    window._setHidden$(NO);

    CGRect inner = window.bounds();
    CGSize navsize = UINavigationBar.$defaultSize();
    CGRect navrect = new CGRect(0, 0, inner.size.width, navsize.height);

    UIView view = new UIView().initWithFrame$(inner);
    window.setContentView$(view);

    UINavigationBar navbar = new UINavigationBar().initWithFrame$(navrect);
    view.addSubview$(navbar);

    navbar.setBarStyle$(1);

    UINavigationItem navitem = new UINavigationItem().initWithTitle$("Contact List");
    navbar.pushNavigationItem$(navitem);

    char letter = 0;
    for (int i = 0; i != contacts_.size(); ++i) {
        String name = contacts_.get(i).getName();
        char now = name.charAt(0);
        if (letter != now) {
            letter = now;
            sections_.add(new Section(
                i,
                new String(new char[] {now})
            ));
        }
    }

    CGRect lower = new CGRect(0, navsize.height, inner.size.width, inner.size.height - navsize.height);
    UISectionList list = new UISectionList().initWithFrame$(lower);
    view.addSubview$(list);

    UITableColumn col = new UITableColumn().initWithTitle$identifier$width$("Name", "name", 320);

    UITable table = (UITable) list.table();
    table.setSeparatorStyle$(1);
    table.addTableColumn$(col);
    table.setReusesTableCells$(YES);

    list.setDataSource$(this);
    list.reloadData();

    /* // XXX: this doesn't work the same on 2.0 and I don't want to think about porting it right now
    AVController controller = new AVController().init();
    CharSequence wavfile = (CharSequence) ((NSBundle) NSBundle.mainBundle()).pathForResource$ofType$("start", "wav");
    AVItem wavitem = new AVItem().initWithPath$error$(wavfile, null);
    wavitem.setVolume$(100);
    controller.setCurrentItem$(wavitem);
    controller.setCurrentTime$(0);
    controller.play$(null);*/
}

}
