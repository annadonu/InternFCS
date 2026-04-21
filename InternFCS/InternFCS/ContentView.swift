import SwiftUI

struct ContentView: View {
    private let bridge = InternFCSBridge()
    @State private var internships: [InternshipModel] = []
    @State private var selectedCategory = "Все"
    
    let categories = ["Все", "Backend", "ML", "Mobile", "Security"]

    var body: some View {
        NavigationView {
            VStack(spacing: 0) {
                Picker("Категория", selection: $selectedCategory) {
                    ForEach(categories, id: \.self) { Text($0) }
                }
                .pickerStyle(.segmented).padding()
                .onChange(of: selectedCategory) { _ in updateList() }

                List(internships, id: \.id) { item in
                    InternshipRow(item: item, bridge: bridge, onUpdate: updateList)
                }
            }
            .navigationTitle("Стажировки ФКН")
            .onAppear {
                bridge.loadData()
                updateList()
            }
        }
    }

    private func updateList() {
        internships = bridge.getInternshipsByTag(selectedCategory)
    }
}

struct InternshipRow: View {
    let item: InternshipModel
    let bridge: InternFCSBridge
    var onUpdate: () -> Void

    var body: some View {
        VStack(alignment: .leading, spacing: 6) {
            HStack {
                Text(item.company).font(.caption).bold().padding(4)
                    .background(Color.blue.opacity(0.1)).cornerRadius(4)
                Spacer()
                
                Text("до \(item.deadline)").font(.caption2).foregroundColor(.secondary)
                Button(action: {
                    bridge.toggleFavorite(item.id)
                    onUpdate()
                }) {
                    Image(systemName: item.isFavorite ? "heart.fill" : "heart").foregroundColor(.red)
                }
            }
            Text(item.title).font(.headline)
            Text(item.desc).font(.subheadline).foregroundColor(.secondary).lineLimit(2)
            Link("Подробнее", destination: URL(string: item.url)!).font(.footnote)
        }
        .padding(.vertical, 4)
    }
}
