var println = function(s) { java.lang.System.out.println(s); }
var sql = Packages.SQLite;

function getName(contact) {
    var name = contact.first;
    if (contact.last != null)
        name += " " + contact.last;
    return name;
}

function numberOfSectionsInSectionList$(list) {
    return sections_.length;
}

function sectionList$titleForSection$(list, section) {
    return sections_[section].title;
}

function sectionList$rowForSection$(list, section) {
    return sections_[section].row;
}

function numberOfRowsInTable$(table) {
    return contacts_.length;
}

function table$cellForRow$column$reusing$(table, row, col, reusing) {
    var contact = contacts_[row];

    var cell;
    if (reusing != null)
        cell = reusing;
    else
        cell = new obc.UIImageAndTextTableCell().init();

    cell.setTitle$(getName(contact));
    return cell;
}

function table$canSelectRow$(table, row) {
    return NO;
}

var contacts_ = [];
var sections_ = [];

var ab = new sql.Database();
ab.open(application.userHomeDirectory().toString() + "/Library/AddressBook/AddressBook.sqlitedb", 0666); try {
    var st = ab.prepare("select first, last from ABPerson where first is not null order by first"); try {
        while (st.step())
            contacts_.push({
                first: st.column_string(0),
                last: st.column_string(1)
            });
    } finally { st.close(); }
} finally { ab.close(); }

var outer = obc.UIHardware.fullScreenApplicationContentRect();
var window = new obc.UIWindow().initWithContentRect$(outer);

window.orderFront$(application);
window.makeKey$(application);
window._setHidden$(NO);

var inner = window.bounds();
var navsize = obc.UINavigationBar().defaultSize();
var navrect = new obc.CGRect(0, 0, inner.size.width, navsize.height);

var view = new obc.UIView().initWithFrame$(inner);
window.setContentView$(view);

var navbar = new obc.UINavigationBar().initWithFrame$(navrect);
view.addSubview$(navbar);

navbar.setBarStyle$(1);

var navitem = new obc.UINavigationItem().initWithTitle$("Contact List");
navbar.pushNavigationItem$(navitem);

var letter = null;
for (var i = 0; i != contacts_.length; ++i) {
    var name = getName(contacts_[i]);
    var now = name[0].toUpperCase();
    if (letter != now) {
        letter = now;
        sections_.push({
            row: i,
            title: now
        });
    }
}

var lower = new obc.CGRect(0, navsize.height, inner.size.width, inner.size.height - navsize.height);
var list = new obc.UISectionList().initWithFrame$(lower);
view.addSubview$(list);

var col = new obc.UITableColumn().initWithTitle$identifier$width$("Name", "name", 320);

var table = list.table();
table.setSeparatorStyle$(1);
table.addTableColumn$(col);
table.setReusesTableCells$(YES);

list.setDataSource$(this);
list.reloadData();

var controller = new obc.AVController().init();
var wavfile = obc.NSBundle().mainBundle().pathForResource$ofType$("start", "wav")
var wavitem = new obc.AVItem().initWithPath$error$(wavfile, null);
wavitem.setVolume$(100);
controller.setCurrentItem$(wavitem);
controller.setCurrentTime$(0);
controller.play$(null);
