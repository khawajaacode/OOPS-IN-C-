       case 7:
                system.generateReport();
                break;
            case 8:
                cout << "Exiting Employee Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}