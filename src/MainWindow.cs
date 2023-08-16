using System;
using Gtk;
using UI = Gtk.Builder.ObjectAttribute;
using Window = Gtk.Window;

namespace TwtApp;

public class MainWindow : Window
{
    [UI] 
    private StatusIcon trayIcon;
    
    [UI] 
    private Menu trayIconMenu;

    [UI]
    private Entry textInput;
    
    public MainWindow() : this(new Builder("MainWindow.glade"))
    {
        
    }

    private MainWindow(Builder builder) : base(builder.GetRawOwnedObject("MainWindow"))
    {
        builder.Autoconnect(this);
        DeleteEvent += OnWindowDelete;
        
        var showItem = new MenuItem("Show");
        var exitItem = new MenuItem("Exit");
        
        trayIconMenu.Append(showItem);
        trayIconMenu.Append(exitItem);
        
        showItem.Activated += OnMenuShowActivated;
        exitItem.Activated += OnMenuExitActivated;

        var cssProvider = new CssProvider();
        cssProvider.LoadFromPath("/home/runsten/src/private/twt-app/src/assets/style.css");
        StyleContext.AddProviderForScreen(Gdk.Screen.Default, cssProvider, StyleProviderPriority.User);
    }

    private void OnWindowDelete(object sender, DeleteEventArgs e)
    {
        Application.Quit();
    }

    private void OnTrayIconPopupMenu(object sender, PopupMenuArgs e)
    {
        trayIconMenu.ShowAll();
        trayIcon.PresentMenu(trayIconMenu, (uint)e.Args[0], (uint)e.Args[1]);
    }
        
    private void OnTrayIconActivated(object sender, EventArgs e)
    {
        Present();
    }

    private void OnMenuShowActivated(object sender, EventArgs e)
    {
        Present();
    }
    
    private void OnMenuExitActivated(object sender, EventArgs e)
    {
        Application.Quit();
    }
}